/*
 * fifo_send.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "../../common/hdr.h"
#include "data.h"
#include "message.h"

void main(void)
{
	Message m;
	m.pid = getpid();
	for(m.number = 1; m.number <= MAXMSG; m.number++) {
		sleep(1);
		if (!sendQueue(5, (char *) &m, sizeof(m)))
			err_sys("Error send");
	}
}
