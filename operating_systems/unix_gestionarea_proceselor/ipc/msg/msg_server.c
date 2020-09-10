/*
 * msg_server.c
 *
 *  Created on: Sep 9, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "mes.h"
#include "../../common/hdr.h"

int msgid;
static void do_it(Message *);
static void sterg(void);

void main(void)
{
	int i, *pint;
	Message mesp;

	if ((msgid = msgget((key_t) KEY, IPC_CREAT | 0666)) < 0)
		err_sys("Error on creating queue messages");
	for(;;) {
		if (msgrcv(msgid, (struct msgbuf *)&mesp, sizeof(mesp) - sizeof(long), 0, 0) < 0)
			err_sys("Server - Error: msgrcv");
		do_it(&mesp);
		mesp.mtip = mesp.pid;
		mesp.pid = getpid();
		if (msgsnd(msgid, (struct msgbuf *)&mesp, sizeof(mesp) - sizeof(long), 0) < 0)
			err_sys("Server - Error: msgsnd");
	}
}

static void do_it(Message *mesp)
{
	switch(mesp -> cod_op) {
	case READ:
		strcpy(mesp->mtext, "Read\n");
		break;
	case WRITE:
		strcpy(mesp->mtext, "Write\n");
		break;
	default:
		strcpy(mesp->mtext, "Unknown\n");
	}
}

static void sterg(void)
{
	if (msgctl(msgid, IPC_RMID, 0) < 0)
		err_sys("Error msgctl");
	exit(0);
}
