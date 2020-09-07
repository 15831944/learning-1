/*
 * sig_system.c
 *run as:
 *sig_system or sig_system1
 *a
 *text
 *w temp.txt
 *5
 *ctrl-C
 *?
 *Received SIGINT
 *q
 *for sig_sistem is not working
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <signal.h>
#include "sig.h"
#include "../common/hdr.h"

void sig_int(int sig)
{
	printf("Received SIGINT\n");
	return;
}

int main()
{
	int status;
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("Error signal(SIGINT,...)");
	if (( status = system("/bin/ed")) < 0)
		err_sys("System error");
	exit(0);
}
