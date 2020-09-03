/*
 * sig_controll.c
 * I do not know how to controll it
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <setjmp.h>
#include <signal.h>
#include "../common/hdr.h"

static void sig_tstp(int);

int main()
{
	int n;
	char buff[MAXLINE];

	//cought SIGTSTP only if we execute controll jobs
	if (signal(SIGTSTP, SIG_IGN) == SIG_ERR)
		signal(SIGTSTP, sig_tstp);
	while( (n = read(0, buff, MAXLINE)) > 0)
		if (write(1, buff, n) != n)
			err_sys("Write error");
	if ( n < 0)
		err_sys("Read error");
	exit(0);
}

static void sig_tstp(int sig)
{
	sigset_t mask;
	/* termio operations */
	//unlock SIGTSTP
	sigemptyset(&mask);
	sigaddset(&mask, SIGTSTP);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	signal(SIGTSTP, SIG_DFL);
	kill(getpid(), SIGTSTP);

	//only if continue
	signal(SIGTSTP, sig_tstp);

	/* termio operations */
	return;
}
