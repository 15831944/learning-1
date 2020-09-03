/*
 * sys4.c
 *system with signals as SVR4
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
	struct sigaction ign, saveintr, savequit;
	sigset_t chldmask, savemask;

	if (cmdstr == NULL)
		return 1;
	ign.sa_handler = SIG_IGN;
	sigemptyset(&ign.sa_mask);
	ign.sa_flags = 0;

	if (sigaction(SIGINT, &ign, &saveintr) < 0)
		return -1;
	if (sigaction(SIGQUIT, &ign, &savequit) < 0)
		return -1;
	sigemptyset(&chldmask);
	sigaddset(&chldmask, SIGCHLD);
	if (sigprocmask(SIG_BLOCK,&chldmask, &savemask) < 0)
		return -1;
	if ((pid = fork()) < 0)
		status = -1;
	else if (pid == 0) {
		//restore actions and mask
		sigaction(SIGINT, &saveintr, NULL);
		sigaction(SIGQUIT, &savequit, NULL);
		sigprocmask(SIG_SETMASK, &savemask, NULL);
		execl("/bin/sh","sh","-c", cmdstr, NULL);
		_exit(127);
	}
	else {
		while(waitpid(pid, &status, 0) < 0)
			if (errno != EINTR) {
				status = -1;
				break;
			}
	}
	//restore actiona and mask
	if (sigaction(SIGINT, &saveintr, NULL) < 0)
		return -1;
	if (sigaction(SIGQUIT, &savequit, NULL) < 0)
		return -1;
	if (sigprocmask(SIG_SETMASK, &savemask, NULL) < 0)
		return -1;
	return status;
}
