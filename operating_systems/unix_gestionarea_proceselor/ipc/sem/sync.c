/*
 * sync.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <stdio.h>
#include "sync.h"
#include "../../common/hdr.h"

void initsem(int semid, int semnr, int val)
{
	semctl(semid, semnr, SETVAL, val);
	printf("mutex = %d\n", val);
}

void config(void)
{
	int semid, i;
	if ((semid = semget(SEMKEY, 1, SEMPERM | IPC_CREAT)) < 0)
		err_sys("Error semget");
	initsem(semid, mutex, 1);
}

void Wait_P(void)
{
	int semid;
	semid = semget(SEMKEY, 0, SEMPERM);
	while(semctl(semid, mutex, GETVAL, 0));
	if (semctl(semid, mutex, IPC_RMID, 0) == 0)
		printf("The semaphore has been deleted from the system\n");
}

void Tell_F(pid_t pid)
{
	int semid;
	semid = semget(SEMKEY, 0, SEMPERM);
	initsem(semid, mutex, 0);
}
