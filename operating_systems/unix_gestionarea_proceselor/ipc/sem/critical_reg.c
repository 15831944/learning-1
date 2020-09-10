/*
 * critical_reg.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pv.h"

#define SEMPERM 0600

void rut_sem(int semid);
int initsem(key_t semkey);

void main(void)
{
	key_t semkey = 0x200;
	int semid;
	semid = initsem(semkey);
	if (fork() == 0)
		rut_sem(semid);
	if (fork() == 0)
		rut_sem(semid);
	if (fork() == 0)
		rut_sem(semid);
}

void rut_sem(int semid)
{
	pid_t pid = getpid();

	P(semid);
	printf("Process %d enter critical region\n", pid);
	sleep(random() %5);
	printf("Process %d leave the critical region\n", pid);
	V(semid);
	exit(0);
}

int initsem(key_t semkey)
{
	int semid;

	semid = semget(semkey, 1, SEMPERM | IPC_CREAT);
	if (semctl(semid, 0, SETVAL, 1) < 0)
		err_sys("Error semctl");
	return semid;
}
