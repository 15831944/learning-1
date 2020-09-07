/*
 * sig_abort.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include "sig_abort.h"
#include "../common/hdr.h"


void abort(void)
{
	struct sigaction act;
	sigset_t mask;
	printf(" A B O R T \n");
	sigaction(SIGABRT, NULL, &act);
	if (act.sa_handler == SIG_IGN) {
		act.sa_handler = SIG_DFL;
		sigaction(SIGABRT, &act, NULL);
	}
	if (act.sa_handler == SIG_DFL)
		fflush(NULL);
	sigfillset(&mask);
	sigdelset(&mask, SIGABRT);
	if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0)
		err_sys("Error sigprocmask(SIG_BLOCK,...)");
	kill(getpid(), SIGABRT);
	fflush(NULL);
	act.sa_handler = SIG_DFL;
	sigaction(SIGABRT, &act,NULL);
	if (sigprocmask(SIG_SETMASK, &mask, NULL) < 0)
		err_sys("Error sigprocmask(SIG_SETMASK,...)");
	kill(getpid(), SIGABRT);
	exit(1);
}
