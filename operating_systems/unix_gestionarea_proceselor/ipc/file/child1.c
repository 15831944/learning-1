/*
 * child1.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "interfata.h"
#include "../../common/hdr.h"

int main()
{
	INTERF interfata;
	int fd;
	if ((fd = open("FIS_INTERF", 0)) < 0)
		err_sys("Error open file");
	if (read(fd, &interfata, sizeof(interfata)) != sizeof(interfata))
		err_sys("Error read from file");
	close(fd);

	printf("Received %s= %f * %d\n",interfata.command, interfata.fvalue, interfata.ivalue);
	fflush(stdout);
	exit(0);
}
