/*
 * pipe_first.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "../../common/hdr.h"

#define PIPE_1 "PIPE_FIFO_1"
#define PIPE_2 "PIPE_FIFO_2"

void parent()
{
	int fd1, fd2;

	if ((fd1 = open(PIPE_1, O_WRONLY)) < 0)
		err_sys("Open error for %s", PIPE_1);
	if ((fd2 = open(PIPE_2, O_RDONLY)) < 0)
		err_sys("Open error for %s", PIPE_2);

	char *mesaj = "From parent!!";
	write(fd1,mesaj, strlen(mesaj)+1);

	char buf[MAXLINE];
	read(fd2,buf, MAXLINE);
	printf("Received %s\n", buf);
	close(fd1);
	close(fd2);
}

void child()
{
	int fd1, fd2;

	if ((fd1 = open(PIPE_1, O_RDONLY)) < 0)
			err_sys("Open error for %s", PIPE_1);
	if ((fd2 = open(PIPE_2, O_WRONLY)) < 0)
		err_sys("Open error for %s", PIPE_2);
	char buf[MAXLINE];
	int n = read(fd1,buf, MAXLINE);
	char *msg = "Received=";
	char *ret = calloc(n+strlen(msg),sizeof(char));
	strcpy(ret, msg);
	strcat(ret,buf);
	write(fd2,ret,strlen(ret));
	close(fd1);
	close(fd2);
}

int main()
{
	int childId;

	mknod(PIPE_1, 0666 | S_IFIFO, 0);
	mknod(PIPE_2, 0666 | S_IFIFO, 0);

	if ((childId = fork()) < 0)
		err_sys("Fork error");
	if (childId)
	{
		parent();
		waitpid(childId, NULL, 0);
		unlink(PIPE_1);
		unlink(PIPE_2);
	}
	else
		child();
	exit(0);
}
