/*
 * msg_client.c
 * run : msg_client [1 | 2]
 *  Created on: Sep 9, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "mes.h"
#include "../../common/hdr.h"

int msgid;
void main(int argc, char *argv[])
{
	pid_t pid;
	Message mesp;
	if (argc < 2)
		err_quit("Usage: %s <cod_opt>", argv[0]);
	if ((msgid = msgget((key_t)KEY, 0666)) < 0)
		err_sys("Error on creating queue message");

	mesp.mtip = 1;
	mesp.cod_op = atoi(argv[1]);
	pid = mesp.pid = getpid();
	printf("The client %d has send the request\n", mesp.pid);
	if (msgsnd(msgid, (struct msgbuf *)&mesp, sizeof(mesp)- sizeof(long), 0) < 0)
		err_sys("Client - Error msgsnd");
	int recSz = 0;
	if ((recSz = msgrcv(msgid, (struct msgbuf *)&mesp, sizeof(mesp) - sizeof(long), 0, 0)) < 0)
		err_sys("Client - Error msgrcv");

	if (recSz > 11)
		mesp.mtext[12] = '\0';
	else
		mesp.mtext[recSz+1]='\0';
	printf("Server: %d -> Client %d has made a request: %s\n", pid, mesp.pid, mesp.mtext);
}
