/*
 * slave_sem.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char **argv, char **env) {
	int fd, i, nloop = 3, *ptr;
	sem_t *sem;
	char SEM_NAME[] = "mysem";

	fd = open("log.txt", O_RDWR, S_IRWXU);
	ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	if ((sem = sem_open(SEM_NAME, 0, 0644, 0)) == SEM_FAILED) {
		perror("slave: unable to open semaphore");
		sem_close(sem);
		exit(1);
	}
	for (i = 0; i < nloop; i++) {
		sem_wait(sem);
		printf("Slave %d entered critical section: %d\n", getpid(),(*ptr)++);
		sleep(2);
		printf("Slave %d leaving critical section\n", getpid());
		sem_post(sem);
		sleep(1);
	}
	sem_close(sem);
	exit(0);
}
