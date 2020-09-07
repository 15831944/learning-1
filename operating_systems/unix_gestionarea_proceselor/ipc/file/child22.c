/*
 * child22.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <stdio.h>
#include <signal.h>
#include "interfata.h"
#include "../../common/hdr.h"
#include <stdlib.h>
#include <fcntl.h>

int exitValue = 0;
pid_t pid;
void sig(int value)
{
	INTERF interfata;
	int fd;
	signal(SIGUSR1, sig);
	if ((fd = open("FIS_INTERF", 0)) < 0)
		err_sys("Error open file child22");
	if (read(fd, &interfata, sizeof(interfata)) != sizeof(interfata))
		err_sys("Error read file child22");
	close(fd);
	printf("Received %s=%f * %d\n", interfata.command, interfata.fvalue, interfata.ivalue);
	fflush(stdout);
	exitValue++;
	if (exitValue == 5)
		exit(0);
	kill(pid, SIGUSR1);
	return;
}

int main(int argc, char *argv[])
{
	pid = atoi(argv[1]);
	signal(SIGUSR1, sig);
	for(;;) {
		if (exitValue == 5)
				exit(0);
		pause();
	}
}
