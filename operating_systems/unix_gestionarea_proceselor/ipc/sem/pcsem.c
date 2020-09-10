/*
 * pcsem.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include "pcsem.h"

key_t semkey = 0x700;
key_t shmkey = 0x800;

int P(int semid, int name)
{
	struct sembuf pbuf;

	pbuf.sem_num = name;
	pbuf.sem_op = -1;
	pbuf.sem_flg = 0;
	semop(semid, &pbuf, 1);
	return 0;
}

int V(int semid, int name)
{
	struct sembuf pbuf;

	pbuf.sem_num = name;
	pbuf.sem_op = 1;
	pbuf.sem_flg = 0;
	semop(semid, &pbuf, 1);
	return 0;
}

void afis(char *p, int l1, int l2)
{
	int i;
	for(i = l1; i < l2 + 1; (i++) % (BUFFMAX + 1))
		putchar(p[i]);
	putchar('\n');
}
