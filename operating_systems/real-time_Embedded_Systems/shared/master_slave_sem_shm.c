/*
 * master_slave_sem_shm.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
	int fd, i, nloop = 3, value = 0, *ptr;
	sem_t *sem;
	int shm;

	fd = open("log.txt", O_RDWR| O_CREAT, S_IRWXU);
	write(fd, &value, sizeof(int));
	ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);

	if ((shm = shm_open("myshm", O_RDWR | O_CREAT, S_IRWXU)) < 0) {
		perror("sh_open");
		exit(1);
	}
	if (ftruncate(shm, sizeof(sem_t)) < 0) {
		perror("ftruncate");
		exit(1);
	}
	if ((sem = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0)) == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
	if (sem_init(sem,1,1) < 0) {
		perror("semphore initialization");
		exit(1);
	}
	if (fork() == 0) {
		for (i = 0; i < nloop; i++) {
			sem_wait(sem);
			printf("child entered critical section: %d\n", (*ptr)++);
			sleep(2);
			printf("child leaving critical section\n");
			sem_post(sem);
			sleep(1);
		}
		sem_close(sem);
		exit(0);
	}
	for(i = 0 ; i < nloop; i++) {
		sem_wait(sem);
		printf("parent enter critial section: %d\n", (*ptr)++);
		sleep(2);
		printf("parent leaving critical section\n");
		sem_post(sem);
		sleep(1);
	}
	sem_destroy(sem);
	exit(1);
}
