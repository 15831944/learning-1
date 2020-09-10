/*
 * fifo_delete.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "../../common/hdr.h"
#include "message.h"

int main(int argc, char *argv[])
{
	if (argc < 0)
		err_sys("Usage: %s <cheie_FIFO>\n", argv[0]);
	rmqueue(atoi(argv[1]));
}
