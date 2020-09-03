/*
 * sys2c
 * system with signals as SVR2
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "sys2.h"

int system(const char *cmdstr)
{
	pid_t pid;
	int status;
	int w;
	static void (*old_intr)(), (*old_quit)();

	if (cmdstr == NULL)
		return(1);
	if ((pid = fork()) < 0)
		status  = -1;
	else if (pid == 0) {
		execl("/bin/sh", "sh", "-c", cmdstr, NULL);
		_exit(127);
	}
	else {
		old_intr = signal(SIGINT, SIG_IGN);
		old_quit = signal(SIGQUIT, SIG_IGN);
		while((w = wait(&status)) != pid && w != -1);
		if (w == -1)
			status = -1;
	}
	signal(SIGINT, old_intr);
	signal(SIGQUIT, old_quit);
	return (status);
}
