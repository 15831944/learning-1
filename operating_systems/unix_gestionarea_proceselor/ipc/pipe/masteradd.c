/*
 * masteradd.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include "../../common/hdr.h"

static void sig_pipe(int sig)
{
	printf("Cought SIGPIPE\n");
	exit(1);
}

int main()
{
	int pfd2[2], pfd1[2], nr;
	char buf[MAXLINE];

	if (signal(SIGPIPE, sig_pipe) == SIG_ERR)
		err_sys("Signal error");
	if (pipe(pfd1) < 0 || pipe(pfd2) < 0)
		err_sys("Pipe error");

	switch(fork()) {
	case -1:
		err_sys("Fork error");
		break;
	case 0:
		if (close(pfd1[1] < 0 | close(pfd2[0]) < 0))
			err_sys("Error close unused");
		close(0);
		if (dup(pfd1[0]) != 0)
			err_sys("Error dup at stdin");
		close(1);
		if (dup(pfd2[1]) != 1)
			err_sys("Error close stdout");
		if (close(pfd2[1]) < 0 || close(pfd1[0]) < 0)
			err_sys("Error close");
		execl("./coprocess","coprocess", NULL);
		err_sys("Error execl");
	}
	//parent
	if (close(pfd2[1]) < 0 || close(pfd1[0]) < 0)
		err_sys("Parent: error close unused");
	while(fgets(buf, MAXLINE,stdin) != NULL) {
		nr = strlen(buf);
		if (write(pfd1[1], buf, nr) != nr)
			err_sys("Error write data in pipe");
		if ((nr = read(pfd2[0], buf, MAXLINE)) < 0)
			err_sys("Error read from pipe");
		if (!nr) {
			err_msg("Child has closed pipe!");
			break;
		}
		buf[nr] ='\0';
		if (fputs(buf, stdout) == EOF)
			err_sys("Error fputs");
	}
	if (ferror(stdin))
		err_sys("Error fgets on stdin");
	exit(0);
}
