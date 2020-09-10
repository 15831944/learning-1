/*
 * message.c
 *
 *  Created on: Sep 9, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "message.h"
#include <errno.h>

static int openqueue(int key)
{
	static struct {
		int key;
		int qid;
	} queues[MAXOPEN];

	int i, avail, qid;
	extern int errno;

	avail = -1; //don't have descriptor

	for (i = 0; i < MAXOPEN; i++) {
		if (queues[i].key == key)
			return(queues[i].qid);
		if (queues[i].key == 0 && avail == -1)
			avail = i;
	}
	if (avail == -1) {
		errno = 0;
		return -1;
	}
	if ((qid = msgget(key, 0666 | IPC_CREAT)) < 0)
		return -1;
	queues[avail].key = key;
	queues[avail].qid = qid;

	return qid;
}


BOOLEAN sendQueue(int dstkey, struct msgbuf *buf, int nbytes)
{
	int qid;
	if ((qid = openqueue(dstkey)) < 0) {
		fprintf(stderr, "Send - Error openqueue\n");
		return FALSE;
	}
	buf -> mtype = 1;
	return (msgsnd(qid, buf, nbytes - sizeof(buf->mtype), 0) != -1);
}

BOOLEAN receiveQueue(int srckey, struct msgbuf *buf, int nbytes)
{
	int qid;
	if ((qid = openqueue(srckey)) < 0) {
		fprintf(stderr, "Receive - Error openqueue\n");
		return FALSE;
	}
	return (msgrcv(qid, buf, nbytes-sizeof(buf->mtype), 0L, 0) != -1);
}

void rmqueue(int key)
{
	int qid;
	if ((qid = openqueue(key)) < 0 || msgctl(qid, IPC_RMID, NULL) < 0)
		err_sys("Error queue");
}
