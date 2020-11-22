/*
 * master.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */


#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **environ) {
	char *args[] = {"slave", NULL};
	int i, status, fd, value = 0;
	posix_spawnattr_t inherit;

	pid_t pid;
	fd = open("log.txt", O_RDWR | O_CREAT, S_IRWXU);
	write(fd, &value, sizeof(int));
	close(fd);
	//create 3 child processes
	for(i = 0; i < 3; i++) {
		inherit.__flags = 0;
		if (posix_spawn(&pid, "slave", NULL, &inherit, args, environ) == -1)
			perror("spawn() failed");
		else
			printf("spawned child, pid = %d\n", pid);
	}
	while(1) {
		if ((pid = wait(&status)) == -1) {
			perror("Master: ");
			exit(EXIT_FAILURE);
		}
		printf("Slave %d terminated\n", pid);
	}
}
