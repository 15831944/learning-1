/*
 * callSystem1.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "../common/hdr.h"

int main(int argc, char *argv[])
{
	int status;
	if (argc < 2)
		err_quit("The porgram need one argument in command line.\n");
	if ((status = system(argv[1])) < 0)
		err_sys("System call error\n");
	print_exit(status);
	exit(0);
}
