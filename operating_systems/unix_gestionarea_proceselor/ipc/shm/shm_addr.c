/*
 * shm_addr.c
 * this will print shared memory addresses
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "../../common/hdr.h"

#define DIM_BUFF 0x20000
#define MALLOC_SIZE 0x50000
#define SHM_SIZE 0x50000
#define SHM_MODE 0666 | IPC_CREAT //SHM_R | SHM_W
#define KEY IPC_PRIVATE

char buf[DIM_BUFF];

int main(void)
{
	int shmid;
	char *p, *shmp;

	printf("String is from address %xh to address %xh\n", &buf[0], &buf[DIM_BUFF]);
	printf("Stack at: %xh\n",&shmid);
	if ((p = malloc(MALLOC_SIZE)) == NULL)
		err_sys("Error malloc");
	printf("Dinamically allocated memory is from address %x to address %x\n",p, p+MALLOC_SIZE );
	if ((shmid = shmget(KEY, SHM_SIZE, SHM_MODE)) < 0)
		err_sys("Error shmget");
	if ((shmp = shmat(shmid, 0, 0)) == (void *)-1)
		err_sys("Error shmat");
	printf("Shared memory is from address %x to address %x with id=%d\n", shmp, shmp+SHM_SIZE, shmid);
	if (shmctl(shmid, IPC_RMID, 0) < 0)
		err_sys("Error shmctl");
	exit(0);
}
