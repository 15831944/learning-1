/*
 * execlp.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include "../common/hdr.h"

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	printf("> ");
	while(fgets(buf,MAXLINE, stdin) != NULL) {
		buf[strlen(buf) -1] = 0;
		if ((pid = fork()) < 0)
			err_sys("Fork error");
		else
			if (pid == 0) {
				execlp(buf,buf,NULL);
				err_ret("Could not executed: %s\n", buf);
				exit(127);
			}
		if ((pid = waitpid(pid, &status,0)) < 0)
			err_sys("Waitpid Error");
		printf("> ");
	}
	exit(0);
}
