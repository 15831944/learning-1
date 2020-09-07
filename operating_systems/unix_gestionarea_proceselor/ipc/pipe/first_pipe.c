/*
 * first_pipe.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../common/hdr.h"

int main(int argc, char *argv[])
{
	int pfd[2], n;
	pid_t pid;
	char buf[MAXLINE];
	char test[] = "test de pipe\n";
	if (pipe(pfd) < 0)
		err_sys("Pipe Error");
	if ((pid = fork()) == -1)
		err_sys("Fork error");
	else if (pid == 0)
	{
		close(pfd[1]);
		n = read(pfd[0], buf, MAXLINE);
		printf("We have read from pipe: %d bytes: ", n);
		fflush(stdout);
		write(1, buf, n);
	}
	else {
		close(pfd[0]);
		write(pfd[1], test, sizeof(test));
	}
	exit(0);
}
