/*
 * ex_exit.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "../common/hdr.h"

int main(void)
{
	pid_t pid;
	if ((pid = fork()) == -1)
		err_sys("Fork error");
	else
		if (pid == 0)
			exit(0);
	sleep(3);
	system("ps");
	exit(0);
}
