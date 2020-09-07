/*
 * cmd_pipe.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/wait.h>
#include <stdlib.h>
#include "../../common/hdr.h"

int main(int argc, char *argv[])
{
	int pfd[2], i, j;
	pid_t pid1, pid2;
	char argv0[20]="/usr/bin/",  *pargv0;
	if (argc < 4) {
		printf("ussage: %s cd1 arg1 [[arg2]...] pipe cd2\n", argv[0]);
		exit(1);
	}
	for(i = 0; argv[i]; i++) {
		if (!strcmp(argv[i],"pipe"))
			break;
	}
	//arguments for cd1
	for(j = 0; j < i - 1; j++)
		argv[j] = argv[j+1];
	argv[i-1] = NULL;
	//cd2
	argv[i] = argv[i+1];
	if (pipe(pfd) < 0)
		err_sys("Pipe error");
	switch(pid1 = fork()) {
	case -1:
		err_sys("Error fork1");
		break;
	case 0:
		close(pfd[0]);
		close(1);
		if (dup(pfd[1]) != 1)
			err_sys("Error dup1");
		close(pfd[1]);
		strcat(argv0, argv[0]);
		execv(argv0, &argv[0]);
		//commands could be also in /bin ??? /usr/bin maybe
		pargv0 = &argv0[4];
		execv(pargv0, &argv[0]);
		err_sys("Error execv: %s", argv0);
	}
	switch(pid2 = fork()) {
	case -1:
		err_sys("Error fork2");
		break;
	case 0:
		close(pfd[1]);
		close(0);
		if (dup(pfd[0]) != 0)
			err_sys("Error dup2");
		close(pfd[0]);
		execlp(argv[i], argv[i], NULL);
		err_sys("Error execlp: %s", argv[i]);
	}
	if (close(pfd[0]) == -1 || close(pfd[1]) == -1)
		err_sys("Close error");
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
