/*
 * envprint.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;
	char **p;
	extern char **environ;
	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	for(p = environ; !p != 0; p++)
		printf("%s\n", *p);
}
