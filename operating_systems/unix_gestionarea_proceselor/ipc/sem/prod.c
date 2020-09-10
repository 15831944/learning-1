/*
 * prod.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "pcsem.h"

extern key_t semkey;
extern key_t shmkey;

void producer(void);

void main()
{
	producer();
}

void put(char ch)
{
	int shmid;
	struct databuf *pbuf;
	char *pd_buf;

	shmid = shmget(shmkey, 0, SEMPERM);
	pbuf = (struct databuf *) shmat(shmid, 0, 0);

	pd_buf = pbuf->d_buff;
	pd_buf[pbuf->nextin] = ch;

	pbuf->nextin = (pbuf -> nextin + 1) %(BUFFMAX + 1);

	afis(pd_buf, 0, 4);
}

void producer(void)
{
	char local;
	int semid, shmid;
	struct databuf *pbuf;

	if ((shmid = shmget(shmkey, sizeof(struct  databuf), SEMPERM)) < 0)
		err_sys("Error shmget");
	if ((pbuf = (struct databuf *)shmat(shmid, NULL, 0)) == NULL)
		err_sys("Error shmat");
	pbuf -> nr_prod++;

	semid = semget(semkey, 0, SEMPERM);

	for(local = 'a'; local <= 'z' ; local++) {
		P(semid, spacesleft);
		P(semid, mutex);
		put(local);
		V(semid, mutex);
		V(semid, itemsready);
	}

	pbuf->nr_prod --;
	exit(0);
}
