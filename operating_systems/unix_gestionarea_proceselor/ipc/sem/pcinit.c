/*
 * pcinit.c
 * producer consumer initialization program
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "pcsem.h"
#include <signal.h>
#include <stdio.h>

extern key_t semkey;
extern key_t shmkey;

int shmid;

void initsem(int semid, int semnr, int val)
{
	semctl(semid, semnr, SETVAL, val);
	printf("Initialization is: semnr=%d, val=%d\n", semnr, val);
}

int main(void)
{
	int semid, i;
	struct databuf *pbuf;

	if ((semid = semget(semkey, N, SEMPERM | IPC_CREAT)) < 0)
		err_sys("Error semget");
	if ((shmid = shmget(shmkey, sizeof(struct  databuf), IPC_CREAT | IPC_EXCL | 0600)) < 0)
		err_sys("Error shmget");
	initsem(semid, spacesleft, BUFFMAX + 1);
	initsem(semid, itemsready, 0);
	initsem(semid, mutex, 1);

	pbuf = (struct databuf *)shmat(shmid, 0,0);
	if (pbuf == NULL)
		err_sys("Error shmat");
	pbuf -> nextin = 0;
	pbuf -> nextout = 0;
	pbuf -> nr_prod = 0;
}
