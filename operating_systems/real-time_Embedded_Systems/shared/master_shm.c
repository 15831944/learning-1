/*
 * master_shm.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 *  adapted from Dave Marsahll, Programming in C [72]
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHMSZ 27

char SHM_NAME[] = "MyShm";

int main() {
	char ch;
	int shmid;
	char *shm, *s;

	if ((shmid = shm_open(SHM_NAME, O_RDWR | O_CREAT, S_IRWXU)) < 0) {
		perror("shm_open");
		return EXIT_FAILURE;
	}
	printf("shmid=%d\n", shmid);
	if (ftruncate(shmid, SHMSZ) == -1) {
		perror("out of memory");
		return EXIT_FAILURE;
	}
	if ((shm = mmap(NULL, SHMSZ, PROT_READ| PROT_WRITE, MAP_SHARED, shmid, 0)) == MAP_FAILED) {
		perror("memory mapping");
		return EXIT_FAILURE;
	}
	s = shm;
	int r;
	for (ch= 'A'; ch <= 'Z'; ch++) {
		*s++ = ch;
		r = rand() % 3;
		sleep(r);
	}

	while(*shm != '*') sleep(1);
	shm_unlink(SHM_NAME);
	return EXIT_SUCCESS;
}
