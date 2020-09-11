/*
 * echod.c
 * concurent server orientated on connection
 *  Created on: Sep 11, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "socket_pasiv.h"

#define QLEN 5
#define BUFSIZE 4096

void handler(int s)
{
	int status;
	while(wait3(&status, WNOHANG, (struct rusage *)0) >=0);
}

int TCPechod(int fd)
{
	char buf[BUFSIZ];
	int ch;

	while((ch = read(fd, buf, sizeof(buf)))) {
		if (ch < 0) {
			printf("echo read: %s\n", sys_errlist[errno]);
			exit(1);
		}
		if (write(fd, buf, ch) < 0) {
			printf("echo write: %s\n", sys_errlist[errno]);
			exit(1);
		}
	}
	return 0;
}

int main(int argc,char **argv)
{
	char *service = "echo";
	struct sockaddr_in fsin;
	int alen;
	int msock; //socket master
	int ssock; //socket slave

	switch(argc) {
	case 1:
		break;
	case 2:
		service = argv[1];
		break;
	default:
		printf("Usage : %s [port]\n", argv[0]);
		exit(1);
	}
	msock = passiveTCP(service, QLEN);
	signal(SIGCHLD, handler);
	while(1) {
		alen = sizeof(fsin);
		ssock = accept(msock, (struct sockaddr *)&fsin, &alen);
		if (ssock < 0) {
			if (errno == EINTR)
				continue;
			printf("Accept: %s'n", sys_errlist[errno]);
			exit(1);
		}
		switch(fork()) {
		case 0:
			close(msock);
			exit(TCPechod(ssock));
		default:
			close(ssock);
			break;
		case -1:
			printf("fork: %s\n",sys_errlist[errno]);
			exit(1);
		}
	}
}

