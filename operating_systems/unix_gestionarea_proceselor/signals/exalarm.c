/*
 * exalarm.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include "../common/hdr.h"
#include <stdlib.h>

static void sig_alarm(int);
int main()
{
	int n;
	char line[MAXLINE];
	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		err_sys("Error signal(SIGALRM,...)");
	alarm(1);
	if ((n = read(0, line, MAXLINE)) < 0)
		err_sys("Read error");
	alarm(0);
	write(1, line, n);
	exit(0);
}

static void sig_alarm(int sig)
{
	return;
}
