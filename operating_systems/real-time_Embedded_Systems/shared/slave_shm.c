/*
 * slave_shm.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 *  adapted from Dave Marsahll, Programming in C [72]
 */

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSZ 27

char SHM_NAME[] = "MyShm";

int main() {
	int shmid;
	char *shm, *s;

	if ((shmid = shm_open(SHM_NAME, O_RDWR, 0)) == -1) {
		perror("client: error opening the shared memory object!\n");
		exit(1);
	}
	if ((shm = mmap(0, SHMSZ, PROT_READ|PROT_WRITE, MAP_SHARED, shmid, 0)) == MAP_FAILED) {
		perror("client: map failed");
		exit(1);
	}

	int i, r;
	for (i = 0; i < 20; i++) {
		printf("1st read:-- %s\n", shm);
		r = rand() %3;
		sleep(r);
		printf("2nd read:-- %s\n", shm);
	}
	*shm = '*';
	exit(0);
}
