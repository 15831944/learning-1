/*
 * cons.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <signal.h>
#include "pcsem.h"

extern key_t semkey;
extern key_t shmkey;

char take(void);
int E_prod_buf(void);
void consumer(void);

int main(void)
{
	consumer();
}

char take()
{
	int shmid;
	struct databuf *pbuf;
	char cch, *pd_buf;

	shmid = shmget(shmkey, 0, SEMPERM);
	pbuf = (struct databuf *)shmat(shmid, 0,0);
	pd_buf = pbuf -> d_buff;

	cch = pd_buf[pbuf->nextout];
	pd_buf [pbuf -> nextout] = ' ';

	pbuf -> nextout = (pbuf -> nextout + 1) % (BUFFMAX + 1);
	return cch;
}

int E_prod_buf()
{
	int shmid;
	struct databuf *pbuf;
	char *pd_buf;

	shmid = shmget(shmkey, 0, SEMPERM);
	pbuf = (struct databuf *)shmat(shmid, 0,0);
	pd_buf = pbuf -> d_buff;

	if (pbuf -> nr_prod == 0 && pd_buf[pbuf->nextout] == ' ') {
		sleep(10);
		if (pbuf ->nr_prod == 0 && pd_buf[pbuf -> nextout] == ' ') {
			kill(SIGTERM, getpid());
			return 0;
		}
		else {
			return 1;
		}
	} else {
		if (pd_buf[pbuf -> nextout] != ' ' || pbuf -> nr_prod > 1)
			return 1;
		sleep(10);
		if (pbuf -> nr_prod == 0) {
			kill(SIGTERM, getpid());
			return 0;
		}
		else
			return 1;
	}
}

void consumer(void)
{
	char local;
	int semid;

	semid = semget(semkey, 0, SEMPERM);
	while(E_prod_buf()) {
		P(semid, itemsready);
		P(semid, mutex);
		local = take();
		printf("Consumer %d: %c\n", getpid(), local);
		V(semid, mutex);
		V(semid, spacesleft);
	}
	printf("Consumer %d finished.\n", getpid());
	exit(0);
}
