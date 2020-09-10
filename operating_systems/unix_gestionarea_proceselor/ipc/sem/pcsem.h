/*
 * pcsem..h
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_SEM_PCSEM_H_
#define IPC_SEM_PCSEM_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "../../common/hdr.h"

#define SEMPERM 0600
#define N 3
#define BUFFMAX 4

struct databuf {
	int nr_prod;
	int nextin;
	int nextout;
	char d_buff[BUFFMAX];
};

typedef enum {
	spacesleft, itemsready, mutex
} semaphore;

int P(int semid, int name);
int V(int semid, int name);
void afis(char *p, int l1, int l2);

#endif /* IPC_SEM_PCSEM_H_ */
