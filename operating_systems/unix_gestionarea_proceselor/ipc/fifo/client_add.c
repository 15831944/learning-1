/*
 * client_add.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include "message.h"
#include "add.h"
#include <stdlib.h>
#include "../../common/hdr.h"

int main(int argc, char *argv[])
{
	Message m;
	int x,y;
	if (argc<3)
		err_quit("Usage: %s <nr1> <nr2>\n", argv[0]);
	m.clientkey = getpid();
	m.x = atoi(argv[1]);
	m.y = atoi(argv[2]);
	if (!sendQueue(SERVERKEY, (char *)&m, sizeof(m)))
		err_sys("Send error");
	if (!receiveQueue(m.clientkey, (char *)&m, sizeof(m)))
		err_sys("Receive error");
	if (m.x+m.y != m.sum)
		err_quit("Inconsistence");
	printf("Sum is = %d\n",m.sum);

	rmqueue(m.clientkey);
	printf("Client %ld was serverd\n",m.clientkey);
	exit(0);
}
