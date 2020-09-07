/*
 * sigchld.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "../common/hdr.h"

static void sig_child(int);

int main()
{
	id_t pid;
	if (signal(SIGCLD, sig_child) == SIG_ERR)
		perror("Error signal(SIGCLD,...)");
	if ((pid = fork()) < 0)
		perror("Error fork()");
	else if(pid ==0) {
		sleep(2);
		exit(0);
	}
	pause();
	exit(0);
}

static void sig_child(int sig)
{
	pid_t pid;
	int status;
	printf("Received SIGCLD\n");
	if (signal(SIGCLD, sig_child) == SIG_ERR)
		perror("Error signal(SIGCLD,...)");
	if ((pid = wait(&status)) < 0)
		perror("Error wait");
	printf("PID for process is %d\n", pid);
	return;
}
