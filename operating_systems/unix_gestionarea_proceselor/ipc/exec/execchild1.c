/*
 * execchild1.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Received %s = %f * %d\n", argv[1], atof(argv[2]), (int)atof(argv[3]));
	fflush(stdout);
}
