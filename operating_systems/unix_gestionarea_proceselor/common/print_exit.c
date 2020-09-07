/*
 * print_exit.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include "print_exit.h"
#include <stdio.h>

extern const char *const sys_siglist[];
void print_exit(int status)
{
	if( WIFEXITED(status))
		printf("Normal termination, exit status=%d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("Abnormal termination, signal number=%d=%s%s\n", WTERMSIG(status), sys_siglist[WTERMSIG(status)],
#ifdef WCOREDUMP
	WCOREDUMP(status) ? "(core file geneated)":"" );
#else
	"");
#endif
	else if (WIFSTOPPED(status))
		printf("Child stopped,signal number=%d%s\n", WSTOPSIG(status), sys_siglist[WSTOPSIG(status)]);
}
