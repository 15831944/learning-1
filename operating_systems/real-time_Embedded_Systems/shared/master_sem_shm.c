/*
 * master_sem_shm.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define SHMSZ 27
char SHM_NAME[] = "myshm";
char SEM_NAME[] = "mysem";

int main() {
	char ch;
	int shmid;
	char *shm, *s;
	sem_t *sem;

	if ((sem = sem_open(SEM_NAME, O_CREAT, 0644, 1)) == SEM_FAILED) {
		perror("unable to create semaphore");
		sem_unlink(SEM_NAME);
		exit(EXIT_FAILURE);
	}
	if ((shmid = shm_open(SHM_NAME, O_RDWR | O_CREAT, S_IRWXU)) < 0) {
		perror("shm_open()");
		sem_unlink(SEM_NAME);
		exit(EXIT_FAILURE);
	}

	if (ftruncate(shmid, SHMSZ) < 0) {
		perror("ftruncate");
		sem_unlink(SEM_NAME);
		shm_unlink(SHM_NAME);
		exit(EXIT_FAILURE);
	}

	if ((shm = mmap(NULL, SHMSZ, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0)) == MAP_FAILED) {
		perror("mmap");
		sem_unlink(SEM_NAME);
		shm_unlink(SHM_NAME);
		exit(EXIT_FAILURE);
	}

	s = shm;
	int r;
	for (ch = 'A'; ch <= 'Z'; ch++) {
		sem_wait(sem);
		*s++ = ch;
		r = rand() % 3;
		sleep(r);
		sem_post(sem);
	}
	while (*shm != '*') {
		sleep(1);
	}
	sem_close(sem);
	sem_unlink(SEM_NAME);
	shm_unlink(SHM_NAME);
	exit(0);
}
