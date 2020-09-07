/*
 * master1.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "interfata.h"
#include "../../common/hdr.h"

int main()
{
	INTERF interfata;
	int fd;
	if ((fd = creat("FIS_INTERF", 0666)) < 0)
		err_sys("Error create interface file");
	sprintf(interfata.command, "%s","command");
	interfata.fvalue = 30.76;
	interfata.ivalue = 27;
	if (write(fd, &interfata, sizeof(interfata)) != sizeof(interfata))
			err_sys("Error write values");
	close(fd);
	pid_t pid;
	if ((pid = fork()) < 0)
		err_sys("Could not fork");
	if (pid  == 0) {
		execl("child1","child1", 0);
		err_sys("Error exec");
	}
	int status;
	if (waitpid(pid, &status, 0) != pid)
		err_sys("Error waitpid");
	exit(0);
}
