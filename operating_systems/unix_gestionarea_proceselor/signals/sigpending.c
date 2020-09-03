/*
 * sigpending.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include "../common/hdr.h"
#include "sig.h"
#include "print_mask.h"

static void sig_quit(int);

int main(void)
{
	sigset_t newmask, oldmask, mask;
	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_sys("Error signal(SIGQUIT,...)");
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("Error sigprocmask(SIG_BLOCK, ...");
	printf("sleep 7s ... zZ");
	sleep(7);
	printf("\t\t\tZz ... ready\n");
	if (sigpending(&mask) < 0)
		err_sys("Error sigpending");
	if (sigismember(&mask, SIGQUIT))
		printf("\nunsolved SIGQUIT \n");
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("Error sigprocmask(SIG_SETMASK,...");
	printf("Signal SIGQUIT unlocked\n");
	printf("Sleep 5s ... zZ\n");
	sleep(5);
	printf("\t\t\tZz ... ready\n");
	exit(0);
}

static void sig_quit(int sig)
{
	printf("Cought signal SIGQUIT\n");
	print_mask("Sig quit mask: ");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("Could not reset signal SIGQUIT");
	return;
}
