/*
 * sigaction.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../common/hdr.h"

void sig_intr(int);

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	if (signal(SIGINT, sig_intr) == SIG_ERR)
		err_sys("Signal error");
	printf("> ");
	while(fgets(buf, MAXLINE, stdin) != NULL) {
		buf[strlen(buf) - 1] = 0;
		if ((pid = fork()) < 0)
			err_sys("Fork error");
		else if (pid == 0) {
			execlp(buf, buf, NULL);
			err_ret("Could not executed : %s", buf);
			exit(127);
		}
		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("Waitpid error");
		printf("> ");
	}
	exit(0);
}

void sig_intr(int sig)
{
	printf("interupt\t\t\tCought signal SIGINT\n> ");
	fflush(stdout);
}
