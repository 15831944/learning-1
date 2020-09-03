/*
 * sleep_ex.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <signal.h>
#include <stddef.h>
#include "../common/hdr.h"

static void sig_alarm(int);

unsigned int sleep(unsigned int sec)
{
	struct sigaction newact, oldact;
	unsigned int rest;
	sigset_t newmask, oldmask, mask;

	newact.sa_handler = sig_alarm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);

	//SIGALRM block and save signal mask
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("Error sigprocmask(SIG_BLOCK, ...)");
	alarm(sec);
	mask = oldmask;
	sigdelset(&mask, SIGALRM);
	sigsuspend(&mask); //wait after a signal
	rest = alarm(0);

	sigaction(SIGALRM, &oldact, NULL);
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("Error sigprocmask(SIG_SETMASK,...)");
	return(rest);
}
int main(void)
{
	printf("rest: %d\n", sleep(10));
}

static void sig_alarm(int sig)
{
	printf("\nAlarm time has elapsed\n");
	return;
}
