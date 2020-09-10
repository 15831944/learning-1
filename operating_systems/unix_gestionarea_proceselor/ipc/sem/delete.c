/*
 * delete.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "messages.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		err_sys("Ussage: %d <key>\n", argv[0]);
	rmqueue(atoi(argv[1]));
}
