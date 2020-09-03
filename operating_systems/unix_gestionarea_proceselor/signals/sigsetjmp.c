/*
 * sigsetjmp.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include "../common/hdr.h"
#include "sig.h"
#include "print_mask.h"

static void sig_usr1(int);
static void sig_alarm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t ok_jump;

int main()
{
	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		err_sys("Error signal(SIGALRM,...)");
	if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
		err_sys("Error signal(SIGUSR1,...)");
	print_mask("In main: MASK= ");
	if (sigsetjmp(jmpbuf, 1)) {
		print_mask("At finish main: MASK= ");
		exit(0);
	}
	ok_jump = 1;
	for(;;)
		pause();
}

static void sig_alarm(int sig)
{
	print_mask("\t\tIn sig_alarm: MASK= ");
	return;
}

static void sig_usr1(int sig)
{
	time_t T_start;
	if (!ok_jump)
		return;
	print_mask("\n\tIn sig_usr1: MASK= ");
	alarm(3);
	T_start = time(NULL);
	for(;;)
		if (time(NULL) > T_start + 5)
			break;
	print_mask("\tAt finish sig_usr1: MASK= ");
	ok_jump = 0;
	siglongjmp(jmpbuf, 1);
}
