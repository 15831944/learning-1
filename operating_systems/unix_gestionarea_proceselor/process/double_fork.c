/*
 * double_fork.c
 * double fork that the parent porcess to now wait for it's child
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../common/hdr.h"
#include "../common/print_exit.h"

int main(void)
{
	pid_t pid;
	if ((pid = fork()) == -1)
		err_sys("Fork 1 error");
	else {
		if (pid == 0) //first child
		{
			if ((pid = fork()) == -1)
				err_sys("Fork 2 error");
			else
				if (pid) //first child = parent from fork 2
					exit(0);
			sleep(3);
			printf("Second child, parent pid = %d\n", getppid());
			exit(0);
		}
	}
	//wait for first child
	if (waitpid(pid, NULL, 0) != pid)
		err_sys("Waitpid error");
	exit(0);
}
