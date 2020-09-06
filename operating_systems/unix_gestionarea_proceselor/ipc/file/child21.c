/*
 * child21.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include "interfata.h"
#include "../../common/hdr.h"

void sig(int value)
{
	signal(SIGUSR1, sig);
	return;
}

int main(int argc, char *argv[])
{
	INTERF interfata;
	int fd;
	pid_t pid = atoi(argv[1]);
	signal(SIGUSR1, sig);
	sprintf(interfata.command, "%s", "command");
	for(int i = 0; i < 5; i++) {
		if ((fd = open("FIS_INTERF", 1)) < 0)
			err_sys("Error open file child21");
		interfata.ivalue = i;
		interfata.fvalue = 2.0*i;
		write(fd, &interfata, sizeof(interfata));
		close(fd);
		kill(pid, SIGUSR1);
		if (i < 4)
			pause();
	}
	exit(0);
}
