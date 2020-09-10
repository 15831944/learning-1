/*
 * receive.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */



#include <stdlib.h>
#include <stdio.h>
#include "../../common/hdr.h"
#include "data.h"
#include "message.h"

int main(void)
{
	Message m;
	setbuf(stdout, NULL);
	while( receiveQueue(5, (char *)&m, sizeof(m)))
		printf("Received %d from %d\n", m.number, m.pid);
	err_sys("Error receive");
}
