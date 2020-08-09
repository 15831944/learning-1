/*
 * onexit.c
 *
 *  Created on: Aug 9, 2020
 *      Author: Gabriel Dimitriu
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void atExit()
{
	printf("Called atExit on pid=%d\n",getpid());
	fflush(stdout);
}

void onExit(int i, void *str) {
	printf("%s on pid %d\n",(char *)str,getpid());
	fflush(stdout);
}

int main(void) {
	pid_t pid, ppid;
	ppid = getpid();
	printf("Parent pid = %d\n", getpid());
	fflush(stdout);
	atexit(atExit);
	on_exit(onExit,"On exit Called");
	pid = fork();
	if (pid == 0) {
		kill(ppid, SIGCHLD);
	} else {
		sleep(10);
		printf("Parent is still alive\n");
		fflush(stdout);
	}
}
