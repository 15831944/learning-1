/*
 * print_mask.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "print_mask.h"

void print_mask(const char *str)
{
	sigset_t sigset;
	int i, errno_save;
	errno_save = errno;
	if (sigprocmask(0, NULL, &sigset) < 0)
		err_sys("Error sigprocmask");
	printf("%s", str);
	for(i = 1; i < NSIG; i++)
		if (sigismember(&sigset, i))
			switch(i) {
			case SIGINT:
				printf("SIGINT ");
				break;
			case SIGQUIT:
				printf("SIGQUIT ");
				break;
			case SIGALRM:
				printf("SIGALRM ");
				break;
			case SIGUSR1:
				printf("SIGUSR1 ");
				break;
			}
	printf("\n");
	errno = errno_save;
}
