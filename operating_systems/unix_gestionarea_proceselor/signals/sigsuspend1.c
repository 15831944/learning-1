/*
 * sigsuspend1.c
 * it works when pres ctrl-C
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include "../common/hdr.h"
#include "sig.h"
#include "print_mask.h"

static void sig_int(int);

int main()
{
	sigset_t newmask, oldmask, mask;
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("Error signal(SIGINT,...)");
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("Error sigprocmask(SIG_BLOCK, ...)");
	//critical region
	print_mask("In critical region MASK= ");
	if (sigsuspend(&mask) != -1)
		err_sys("Error sigsuspend");
	print_mask("After return from critical region MASK= ");
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("Error sigprocmask(SIG_SETMASK,...");
	exit(0);
}

static void sig_int(int sig)
{
	print_mask("In sig_int: MASK= ");
	return;
}
