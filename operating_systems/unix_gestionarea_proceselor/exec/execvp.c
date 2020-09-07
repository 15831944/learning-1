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
				char **argv;
				char *tmp = (char *)calloc(strlen(buf)+ 1, sizeof(char));
				strcpy(tmp, buf);
				char *command = strtok(tmp," ");
				int nrArgs = -1;
				while(command != NULL) {
					nrArgs++;
					command = strtok(NULL," ");
				}
				if (nrArgs == 0) {
					argv = (char **)calloc(1,sizeof(char *));
					argv[0]=buf;
				}
				else {
					argv = (char **)calloc(nrArgs + 1,sizeof(char *));
					strcpy(tmp,buf);
					nrArgs = 0;
					command = strtok(tmp," ");
					while(command != NULL) {
						argv[nrArgs] = command;
						command = strtok(NULL," ");
						nrArgs++;
					}
				}
				execvp(argv[0],argv);
				err_ret("Could not executed: %s:\n", argv[0]);
				exit(127);
			}
		if ((pid = waitpid(pid, &status,0)) < 0)
			err_sys("Waitpid Error");
		printf("> ");
	}
	exit(0);
}
