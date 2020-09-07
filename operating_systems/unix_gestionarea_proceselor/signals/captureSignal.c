/*
 * captureSignal.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include "../common/hdr.h"

static void sig_usr1(int); //kill -USR1 <pid>
static void sig_intr(int); //ctrl-C
static void sig_quit(int); /* ctrl-\ */ //doesn't trigger with kill -s SIGQUIT pid
static void sig_alarm(int);

int main()
{
	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		err_sys("Error signal(SIGALARM,...)");
	if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
		err_sys("Error signal(SIGUSR1,...)");
	if (signal(SIGINT, sig_intr) == SIG_ERR)
		err_sys("Error signal(SIGINT,...)");
	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_sys("Error signal(SIGQUIT,...)");
	for(;;)
		pause();
}

static void sig_alarm(int sig)
{
	printf("Receive signal SIGALARM\n");
	return;
}

static void sig_quit(int sig)
{
	printf("Receive signal SIGQUIT\n");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("Could not reset this signal ... ");
	return;
}

static void sig_intr(int sig)
{
	printf("Receive signal SIGINT\n");
	if (signal(SIGINT, sig_intr) == SIG_ERR)
		err_sys("Could not reset this signal ... ");
			return;
}

static void sig_usr1(int sig)
{
	printf("Receive signal SIGUSR1\n");
	alarm(1);
	printf("Allarm will be trigerred after 1 sec !.\n");
	return;
}
