/*
 * nmap_ex.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "../../common/hdr.h"
#include "../pipe/sync.h"

#define NRLOPPS 1000
#define SIZE sizeof(long)

static int update(long *);

int main(void)
{
	int fd, nr, i;
	pid_t pid;
	caddr_t zone;

	if ((fd = open("/dev/zero",O_RDWR)) < 0)
		err_sys("Error open");
	if (( zone = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == (caddr_t)-1)
		err_sys("Error mmap");
	close(fd);

	config();
	switch(pid = fork()) {
	case -1:
		err_sys("Error fork");
		break;
	case 0:
		for (i = 0; i < NRLOPPS; i+=2) {
			Wait_P();
			if ((nr = update((long *)zone)) != i)
				err_quit("Child: wait %d, received %d",i, nr);
			Tell_F(pid);
		}
		break;
	default:
		for (i = 0; i < NRLOPPS; i+=2) {
			if ((nr = update((long *)zone)) != i)
				err_quit("Parent: wait %d, received %d", i, nr);
			Tell_F(pid);
			Wait_P();
		}
	}
	exit(0);

}

static int update(long *ptr)
{
	return (*ptr)++;
}
