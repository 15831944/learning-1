/*
 * semaphore.c
 *
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
	/* union semnum is defined by including <sys/sem.h> */
#else
	/* we have to define ourself */
union semun {
	int val; /* value for SETVAL */
	struct semid_ds *buf; /* buffer for IPC_STAT, IPC_SET */
	unsigned short int *array; /* array for GETALL, SETALL */
	struct seminfo *__buf; /* buffer for IPC_INFO */
};
#endif

void main() {
	key_t unique_key;
	int id;
	struct sembuf lock_it;
	union semun options;
	int i;
	/* start createing a semaphore */
	unique_key = ftok(".",'s');
	printf("unique key = %d\n", unique_key);
	/* if you want to use semaphore created by other program use 0 as second argument */
	id = semget(unique_key, 1, IPC_CREAT |  0666);
	if (id <= 0) {
		perror("could not create semaphore");
		exit(1);
	}
	printf("semaphore id = %d\n", id);
	options.val = 1;
	semctl(id, 0, SETVAL, options);
	/* make sure that everything is set up OK */
	if (semctl(id, 0, GETVAL, 0) == 0) {
		perror("can not lock semaphore.\n");
		exit(1);
	}
	i = semctl(id, 0, GETVAL , 0);
	printf("value of semaphore at index 0 is %d\n", i);
	lock_it.sem_num = 0;
	lock_it.sem_op = -1;
	lock_it.sem_flg = IPC_NOWAIT;
	if(semop(id, &lock_it, 1) == -1) {
		perror("can not lock semaphore.\n");
		exit(1);
	}
	i = semctl(id, 0, GETVAL, 0);
	printf("value of semaphore at index 0 is %d\n", i);

	lock_it.sem_num = 0;
	lock_it.sem_op = 1;
	lock_it.sem_flg = IPC_NOWAIT;
	if (semop(id, &lock_it, 1) == -1) {
		perror("can not unlock semaphore.\n");
		exit(1);
	}
	i = semctl(id, 0, GETVAL, 0);
	printf("value of semaphore at index 0 is %d\n", i);

	semctl(id, 0, IPC_RMID, 0);

}
