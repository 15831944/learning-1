/*
 * pccleanup.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "pcsem.h"
#include <stdlib.h>

extern key_t semkey;
extern key_t shmkey;

int main(void)
{
	int shmid, semid;
	if ((shmid = shmget(shmkey, 0, 0 )) < 0)
		perror("Error - the shared memory doesn't exist ");
	if (shmctl(shmid, IPC_RMID, NULL) < 0)
		perror("Error shmctl");
	if ((semid = semget(semkey, 0, 0)) < 0)
		perror("Error - the semaphores doesn't exist");
	if (semctl(semid, 0, IPC_RMID, 0) < 0)
		perror("Error semctl");
	printf("OK.\n");
	exit(0);
}
