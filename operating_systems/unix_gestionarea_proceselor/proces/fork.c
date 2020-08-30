/*
 * fork.c
 * usage of fork
 * if the fflush is uncommented then when redirected the output will be the same
 * otherwise on redirected the Before fork() is printed also for the child because
 * the stdout buffer is not emptied.
 * if vfork is used insead of fork and sleep is commentd the parent will have the
 * same data (modified as child).
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <unistd.h>
#include "../common/hdr.h"

int gvar = 4;

int main(void)
{
	pid_t pid;
	int var = 7;
	printf("Before fork()\n");
//	fflush(stdout);
	if ((pid = fork()) == -1)
		err_sys("Fork error");
	else {
		if (pid == 0) {
			gvar++;
			var +=2 ;
		}
		else
			sleep(2);
	}
	printf("Process (pid) = %d, gvar = %d, var=%d\n", getpid(), gvar, var);
/*	if (pid == 0)
		_exit(0);
	else */
		exit(0);
}
