/*
 * slave.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char **argv,char **env) {
	int fd, i, nloop = 3, *ptr;

	fd = open("log.txt", O_RDWR, S_IRWXU);
	ptr =mmap(NULL, sizeof(int), PROT_READ |PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);

	for (i = 0; i < nloop; i++) {
		printf("Slave %d starts processing data: %d\n", getpid(), (*ptr)++);
		sleep(2);
		printf("Slave %d  stops processing data\n", getpid());
		sleep(1);
	}
	exit(0);

}
