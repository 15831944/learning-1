/*
 * sys.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include "sys.h"

int system(const char *cmdstr)
{
	pid_t pid;
	int status;
	int w;
	static void (*old_intr)(),(*old_quit)();
	if (cmdstr == NULL)
		return(1);
	if ((pid = fork()) < 0)
		status = -1;
	else
		if(pid == 0) {
			execl("/bin/sh", "sh", "-c", cmdstr, NULL);
			_exit(127);
		}
		else {
			while(waitpid(pid, &status, 0) < 0)
				if (errno != EINTR) {
					status = -1;
					break;
				}
		}
	return(status);
}
