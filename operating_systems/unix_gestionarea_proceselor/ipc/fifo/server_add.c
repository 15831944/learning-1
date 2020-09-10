/*
 * add.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "add.h"
#include "../../common/hdr.h"
#include "message.h"

void main(void)
{
	Message m;
	extern int errno;
	while(receiveQueue(SERVERKEY, (char *)&m, sizeof(m))) {
		m.sum = m.x + m.y;
		if (!sendQueue(m.clientkey, (char *)&m, sizeof(m)))
			printf("Could not send %ld; errno=%d\n", m.clientkey, errno);
	}
	err_sys("Error receive");
}
