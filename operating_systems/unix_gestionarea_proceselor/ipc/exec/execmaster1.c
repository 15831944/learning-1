/*
 * execmaster1.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int ivalue = 27;
	char *str1 = "command";
	float fvalue = 36.0f;
	pid_t pid;
	if ((pid = fork()) < 0)
		perror("Error fork");
	if (pid == 0) {
		char cfvalue[10];
		gcvt(fvalue, 10,cfvalue);
		char civalue[10];
		gcvt(ivalue, 10, civalue);
		execl("execchild1","execchild1", str1, cfvalue, civalue, (char *)0);
		printf("Error exec");
		exit(127);
	} else {
		int status;
		if (waitpid(pid,&status, 0) != pid) {
			perror("Error waitpid");
		}
	}
}
