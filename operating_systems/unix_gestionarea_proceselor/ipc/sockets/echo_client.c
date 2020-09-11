/*
 * echo_client.c
 *
 *  Created on: Sep 11, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "client_proc.h"

#define LINELEN 1024

extern int errno;
extern const char * const sys_errlist[];

int TCPUDPecho(char *, char *);

int main(int argc, char *argv[])
{
	char *host = "localhost";
	char *service = "echo";

	switch(argc) {
	case 1:
		break;
	case 3:
		service = argv[2];
	case 2:
		host = argv[1];
		break;
	default:
		printf("usage: %s [host [service]]\n", argv[0]);
		exit(1);
	}
	TCPUDPecho(host, service);
}

int TCPUDPecho(char *host, char *service)
{
	char bufs[LINELEN + 1];
	int s, n;
	int outchs, inchs; //nr or send/received characters

#ifdef TCP
	s = connectTCP(host, service);
#endif
#ifdef UDP
	s = connectUDP(host, service);
#endif
	while(fgets(bufs, sizeof(bufs), stdin)) {
		bufs[LINELEN + 1] = '\0';
		outchs = strlen(bufs);
		write(s, bufs, outchs);
#ifdef TCP
		for (inchs = 0; inchs < outchs; inchs+=n) {
			n = read(s, &bufs[inchs], outchs - inchs);
			if (n < 0) {
				printf("Socket read failed: %s\n", sys_errlist[errno]);
				exit(1);
			}
		}
#endif
#ifdef UDP
		if (read(s,bufs, outchs) < 0) {
			printf("socket read failed: %s\n", sys_errlist[errno]);
			exit(1);
		}
#endif
		fputs(bufs, stdout);
	}
}
