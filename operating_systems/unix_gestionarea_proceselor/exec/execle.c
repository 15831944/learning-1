/*
 * execle.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <sys/types.h>
#include <sys/wait.h>
#include "../common/hdr.h"

char *env_init[] = {"LOGNAME=unknown", "PATH=/tmp", NULL};

int main(void)
{
	pid_t pid;
	if ((pid = fork()) == -1)
		err_sys("Fork error 1");
	else if (pid == 0)
		if (execle("/home/onion/learning/operating_systems/unix_gestionarea_proceselor/exec/envprint", "envprint","arg1","ARG2", NULL, env_init)< 0)
			err_sys("Execle error");
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("Error waitpid");
	if ((pid = fork()) == -1)
		err_sys("Fork error 2");
	else if (pid == 0)
		if (execlp("envprint", "envprint","arg_is_one", NULL) < 0)
			err_sys("Error execlp");
	exit(0);
}
