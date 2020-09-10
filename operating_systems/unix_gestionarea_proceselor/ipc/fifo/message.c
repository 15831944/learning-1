/*
 * mesaje.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "message.h"

#include <stdio.h>
#include "../../common/hdr.h"
/*
 * make the name of the FIFO
 */
static char *fifoname(int key)
{
	static char fifo[20];
	sprintf(fifo,"/tmp/fifo%d", key);
	return fifo;
}

static int makefifo(char *path)
{
	return (mknod(path, S_IFIFO | 0666, 0));
}

/*
 * get the descriptor
 */
static int openfifo(int key, int flags)
{
	static struct {
		int key; //key of file
		int fd; //descriptor
		int time; //last access time
	} fifos[MAXOPEN];

	static int clock;
	int i, avail, oldest, fd, tries;
	char *fifo;
	extern int errno;

	clock++;
	avail = -1;
	for(i = 0; i < MAXOPEN; i++) {
		if (fifos[i].key == key) {
			fifos[i].time = clock;
			return (fifos[i].fd);
		}
		if (fifos[i].key == 0 && avail == -1)
			avail = i;
	}
	if (avail == -1) {
		oldest = -1;
		for(i = 0; i < MAXOPEN; i++)
			if (oldest == -1 || fifos[i].time < oldest ) {
				oldest = fifos[i].time;
				avail = i;
			}
		if (close(fifos[avail].fd) < 0)
			return(-1);
	}
	fifo = fifoname(key);
	if (makefifo(fifo) < 0 && errno != EEXIST)
		return -1;
	for (tries = 1; tries <= MAXTRIES; tries++) {
		if ((fd = open(fifo, flags | O_NDELAY)) != -1) {
			break;
		}
		if (errno != ENXIO) //dont' exist FIFO
			return -1;
		sleep(NAPTIME);
	}
	if (fd == -1) {
		errno = ENXIO;
		return -1;
	}

	if (fcntl(fd, F_SETFL, flags) < 0) {
		return -1;
	}
	fifos[avail].key = key;
	fifos[avail].fd = fd;
	fifos[avail].time = clock;
	return fd;
}

int sendQueue(int dstkey, char *buf, int nbytes)
{
	int fd, nw;
	if((fd = openfifo(dstkey, O_WRONLY)) < 0) {
		fprintf(stderr,"Send - Error openfifo\n");
		return FALSE;
	}
	return (write(fd, buf, nbytes) != -1);
}

int receiveQueue(int srckey, char *buf, int nbytes)
{
	int fd, nread;
	if ((fd = openfifo(srckey, O_RDONLY)) < 0) {
		fprintf(stderr,"Receive - Error openfifo\n");
		return FALSE;
	}
	while((nread = read(fd, buf, nbytes)) == 0)
		sleep(NAPTIME);
	return (nread != -1);
}

void rmqueue(int key)
{
	extern int errno;
	if (unlink(fifoname(key)) < 0 && errno != ENOENT)
		err_sys("Error unlink %s", fifoname(key));
}
