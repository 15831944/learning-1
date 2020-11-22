/*
 * slave_sem_shm.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SHMSZ 27
char SHM_NAME[] = "myshm";
char SEM_NAME[] = "mysem";

int main() {
	char ch;
	int shmid;
	char *shm, *s;
	sem_t *sem;

	if ((sem = sem_open(SEM_NAME,0, 0644, 0)) == SEM_FAILED) {
		perror("Slave: unable to create semaphore");
		sem_close(sem);
		exit(EXIT_FAILURE);
	}
	if ((shmid = shm_open(SHM_NAME, O_RDWR , 0)) < 0) {
		perror("Slave: shm_open()");
		sem_close(sem);
		exit(EXIT_FAILURE);
	}

	if ((shm = mmap(0, SHMSZ, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0)) == MAP_FAILED) {
		perror("Slave: mmap");
		sem_close(sem);
		exit(EXIT_FAILURE);
	}

	int i, r;
	for (i = 0; i < 20 ; i++) {
		sem_wait(sem);
		printf("1st read:--- %s\n", shm);
		r = rand() % 3;
		sleep(r);
		printf("2nd read:--- %s\n", shm);
		sem_post(sem);
	}

	*shm= '*';
	sem_close(sem);
	exit(0);
}
