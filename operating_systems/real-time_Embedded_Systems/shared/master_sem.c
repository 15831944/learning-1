/*
 * master_sem.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv, char **env) {
	char SEM_NAME[] = "mysem";
	char *args[] = {"slave_sem", NULL};
	int i, status, fd, value = 0;
	posix_spawnattr_t inherit;
	pid_t pid;
	sem_t *sem;

	fd = open("log.txt", O_RDWR | O_CREAT, S_IRWXU);
	write(fd, &value, sizeof(int));
	close(fd);

	if((sem = sem_open(SEM_NAME, O_CREAT, 0644, 1)) == SEM_FAILED) {
		perror("unable to create semaphore");
		sem_unlink(SEM_NAME);
		exit(1);
	}

	//create 3 child processes
	for (i = 0; i < 3; i++) {
		inherit.__flags = 0;
		if (posix_spawn(&pid, "slave_sem", NULL, &inherit, args, env) == -1)
			perror("spawn() failed");
		else
			printf("spawned child, pid = %d\n", pid);
	}
	while(1) {
		if ((pid = wait(&status)) == -1) {
			perror("Master: ");
			sem_unlink(SEM_NAME);
			exit(EXIT_FAILURE);
		}
		printf("Slave %d terminated\n", pid);
	}
}
