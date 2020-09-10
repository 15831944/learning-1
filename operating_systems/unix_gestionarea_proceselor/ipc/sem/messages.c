/*
 * messages.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "messages.h"
#include <errno.h>

static int findinfo(int key, int *sndsp, int *rcvsp, char **adrp, int *shmidp)
{
	int semid_s , semid_r;

	static struct {
		int key; //key for the messaging queue
		int snds; //sending semaphore
		int rcvs; //receiving semphore
		char *adr; //shared memory address
		int shmdid; //id of the shared memory
	} semafs[MAXOPEN];
	int i, avail;
	extern int errno;
	avail = -1;

	for (i = 0; i < MAXOPEN; i++) {
		if (semafs[i].key == key) {
			*sndsp = semafs[i].snds;
			*rcvsp = semafs[i].rcvs;
			*shmidp = semafs[i].shmdid;
			*adrp = semafs[i].adr;
			return TRUE;
		}
		if (semafs[i].key == 0 && avail == -1)
			avail = i;
 	}
	if (avail == -1) {
		errno = 0;
		return FALSE;
	}
	semafs[avail].key = key;

	if ((semid_s = semget((key_t) key, 1, 0600 | IPC_CREAT)) < 0)
		err_sys("Error semget send");
	*sndsp = semafs[avail].snds = semid_s;

	semctl(semid_s, 0, SETVAL, 1);

	if ((semid_r = semget((key_t) key+1000, 1 , 0600 | IPC_CREAT)) < 0)
		err_sys("Error semget receive");

	*rcvsp = semafs[avail].rcvs = semid_r;
	semctl(semid_r, 0, SETVAL, 0);

	if ((*shmidp = semafs[avail].shmdid = shmget((key_t) key, MAXMSG, 0600 | IPC_CREAT)) < 0)
		return FALSE;

	if ((*adrp = semafs[avail].adr = shmat(*shmidp, 0, 0)) < (char *)0)
		return FALSE;
	return TRUE;
}

int send(int key, char *buf, int nbytes)
{
	int snds, rcvs, shmid;
	char *adr;

	if (!findinfo(key, &snds, &rcvs, &adr, &shmid))
		return FALSE;
	if (nbytes > MAXMSG)
		nbytes = MAXMSG;
	P(snds);
	memcpy(adr, buf, nbytes);
	V(rcvs);
	return TRUE;
}

int receive(int key, char *buf, int nbytes)
{
	int snds, rcvs, shmid;
	char *adr;

	if (!findinfo(key, &snds, &rcvs, &adr, &shmid))
		return FALSE;

	if (nbytes > MAXMSG)
		nbytes = MAXMSG;
	P(rcvs);
	memcpy(buf, adr, nbytes);
	V(snds);
	return TRUE;
}

void rmqueue(int key)
{
	int snds, rcvs, shmid;
	char *adr;

	if (!findinfo(key, &snds, &rcvs, &adr, &shmid))
		err_sys("Error findinfo");
	if (semctl(snds, 0, IPC_RMID, 0) < 0)
		err_sys("Error semctl(rcvs, ...");
	if (shmdt(adr) < 0)
		err_sys("Error shmdt");
	if (shmctl(shmid, IPC_RMID, 0) < 0)
		err_sys("Error shmctl");
}

