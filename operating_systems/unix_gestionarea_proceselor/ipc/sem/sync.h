/*
 * sync.h
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_SEM_SYNC_H_
#define IPC_SEM_SYNC_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 0x77
#define SEMPERM 0600
#define mutex 0

void initsem(int semid, int semnr, int val);
void config(void);
void Wait_P(void);
void Tell_F(pid_t pid);

#endif /* IPC_SEM_SYNC_H_ */
