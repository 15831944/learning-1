/*
 * messages.h
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_SEM_MESSAGES_H_
#define IPC_SEM_MESSAGES_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "pv.h"
#include "../../common/hdr.h"

#define MAXOPEN  20
#define MAXMSG 4
#define TRUE 1
#define FALSE 0

int send(int key, char *buf, int nbytes);
int receive(int key, char *buf, int nbytes);
void rmqueue(int key);

#endif /* IPC_SEM_MESSAGES_H_ */
