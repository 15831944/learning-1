/*
 * sig_critical_srv4.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include "../common/hdr.h"
#include "sig.h"
#include "print_mask.h"

static volatile sig_atomic_t in_reg;
static sigjmp_buf jmpbuf;

static void sig_int(int);

int read_line(char *);

int main()
{
	int nr_car;
	char buff[MAXLINE];

	sigset_t newmask, oldmask, mask;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("Error signal(SIGINT,...)");
	if (sigsetjmp(jmpbuf, 1)) {
		printf("The program was interrupted using signal !\n");
		exit(1);
	}
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	while(1) {
		if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
			err_sys("Error sigprocmask(SIG_BLOCK,...)");
		nr_car = read_line(buff);
		if (nr_car > 0)
			printf("%s\n", buff);
		else break;
		if (sigismember(&mask, SIGINT))
			printf("\nUnsolved SIGINT\n");
		if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
			err_sys("Error sigprocmask(SIG_SETMAX,...)");
	}
	printf("Program is terminated normally! \n");
	exit(0);
}

void sig_int(int sig)
{
	siglongjmp(jmpbuf, 1);
}

int read_line(char *buff)
{
	char c;
	int i = 0;
	for(c = getchar(); i < MAXLINE && c != '\n'; c = getchar())
		buff[i++] = c;
	buff[i] = '\0';
	return i;
}
