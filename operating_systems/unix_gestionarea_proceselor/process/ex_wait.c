/*
 * ex_wait.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../common/hdr.h"
#include "../common/print_exit.h"

int main(void)
{
	pid_t pid;
	int status;
	if ((pid = fork()) == -1)
		err_sys("Fork error");
	else
		if(pid == 0)
			exit(7);
	if (wait(&status) != pid)
		err_sys("Wait error");
	print_exit(status);
	if((pid = fork()) == -1)
		err_sys("Fork error");
	else
		if (pid == 0)
			status /=0; //generate SIGPPE
	if (wait(&status) != pid)
		err_sys("Wait error");
	print_exit(status);
	if ((pid = fork()) == -1)
		err_sys("Fork error");
	else
		if (pid == 0)
			abort(); // generate SIGABRT
	if (wait(&status) != pid)
		err_sys("Wait error");
	print_exit(status);
	exit(0);
}
