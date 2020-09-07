/*
 * exsetjmp.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <setjmp.h>
#include <signal.h>
#include "../common/hdr.h"

static void sig_alarm(int);
static jmp_buf env_alarm;

int main(void)
{
	int n;
	char line[MAXLINE];
	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		err_sys("Error signal(SIGALRM, ...)");
	if (setjmp(env_alarm) != 0)
		err_quit("Read time is expired");
	alarm(10);
	if ((n = read(0, line, MAXLINE)) < 0)
		err_sys("Read error");
	alarm(0);
	write(1, line, n);
	exit(0);
}

static void sig_alarm(int sig)
{
	longjmp(env_alarm, 1);
}
