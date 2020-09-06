/*
 * master2.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../../common/hdr.h"
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd;
	pid_t pid1;
	pid_t pid2;
	char buf[10];
	if ((fd = creat("FIS_INTERF", 0660)) < 0)
		err_sys("Error creat");
	close(fd);
	pid1 = getpid();
	if((pid2 = fork()) == -1)
		err_sys("Error fork");
	if (pid2 == 0) {
		execl("child22", "child22", gcvt(pid1, 10, buf), NULL);
		err_sys("Error exec chidl22");
	}
	else {
		sleep(1); // this is need because otherwise we have no child ...
		execl("child21", "child21", gcvt(pid2, 10, buf), NULL);
		err_sys("Error exec child21");
	}
}
