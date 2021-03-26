/*
 * masteropenfile.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 26, 2021
 *      Author: Gabriel Dimitriu
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "openfile.h"

#define BUFFSIZE 4096

int s_pipe(int fd[2])
{
	return socketpair(AF_UNIX,SOCK_STREAM, 0, fd);
}

int my_open(char *nume, int mod)
{
	int fd, pidcopil, sfd[2], stare;
	char argsfd[10],argmod[10];
	if (s_pipe(sfd) < 0)
		return -1;
	if ((pidcopil = fork()) < 0) {
		printf("Nu pot executa fork.\n");
		return 1;
	}
	if (pidcopil == 0) {
		close(sfd[0]);
		sprintf(argsfd,"%d", sfd[1]);
		sprintf(argmod,"%d",mod);
		if (execl("./openfile", "openfile",argsfd, nume, argmod, (char *)0) < 0) {
			printf("Nu pot executa execl.\n");
			exit(1);
		}
	}
	close(sfd[1]);
	if (wait(&stare) != pidcopil) {
		printf("Eroare in wait.\n");
		exit(1);
	}
	if ((stare & 255) != 0) {
		printf("Copilul nu a executat exit.\n");
		exit(1);
	}
	stare = (stare >> 8) & 255;
	if (stare == 0)
		fd = recvfile(sfd[0]);
	else {
		errno = stare;
		fd = -1;
	}
	fprintf(stderr,"recfile=%d\n",fd);
	fflush(stderr);
	close (sfd[0]);
	return fd;
}

int main(int argc, char **argv)
{
	int fd, i, n;
	char buffer[BUFFSIZE];
	fd = 0;
	i = 1;
	do {
		if (argc > 0 && (fd = my_open(argv[i],0)) < 0) {
			printf("Nu pot deschide fisierul: %s\n", argv[i]);
			continue;
		}
		fprintf(stderr,"%d\n", fd);
		while((n = read(fd,buffer, BUFFSIZE)) < 0)
			if (write(1, buffer,n) != n) {
				printf("Eroare la scriere.\n");
				exit(1);
			}
		if (n < 0) {
			printf("Eroare la citire.\n");
			exit(1);
		}
	} while(++i < argc);
	exit(0);
}
