/*
 * sig_proc_terminate.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sig_abort.h"
#include "../common/hdr.h"


int main(void)
{
	pid_t pid;
	int status, cod;
	if ((pid = fork()) == -1)
		err_sys("Fork error");
	if (pid) {
		if (wait(&status) != pid)
			err_sys("Wait error");
		if (( cod = status & 0177) <= NSIG)
			printf("Child has ended with: %s\n", sys_siglist[cod]);
		else
			printf("Signal #%d",cod);
		if ((status & 0200) == 0200)
			printf("Empty memory\n");
		exit(0);
	} else {
		printf("Child executing\n");
		abort(); //generate SIGART
	}
}
