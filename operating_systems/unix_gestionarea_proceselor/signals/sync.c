/*
 * sync.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include "sync.h"

static volatile sig_atomic_t sigfan;
static sigset_t newmask, oldmask, mask;
static void sig_int(int);

void config(void)
{
	if (signal(SIGUSR1, sig_int) == SIG_ERR)
		err_sys("Error signal(SIGUSR1,...)");
	if (signal(SIGUSR2, sig_int) == SIG_ERR)
		err_sys("Error signal(SIGUSR2,...)");
	sigemptyset(&mask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);
	//block SIGUSR1 and SIGUSR2 and save current mask
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("config:Error sigprocmask(SIG_BLOCL,...)");
}


void Tell_P(pid_t pid)
{
	kill(pid, SIGUSR2);
}

void Wait_P(void)
{
	while(!sigfan)
		sigsuspend(&mask);
	sigfan = 0;
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("Wait_P:Error sigprocmask(SIG_SETMASK,...)");
}

void Tell_F(pid_t pid)
{
	kill(pid, SIGUSR1);
}

void Wait_F(void)
{
	while(sigfan == 0)
		sigsuspend(&mask);
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("Wait_F:Error sigprocmask(SIG_SETMASK, ...)");
}
static void sig_int(int sig)
{
	sigfan = 1;
	return;
}
