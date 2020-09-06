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
	char str[20];
	int ivalue;
	float fvalue;

	printf("Received as argument %s\n", argv[1]);
	fflush(stdout);
	sscanf(argv[1], "%s %f %d",str, &fvalue, &ivalue);
	printf("Received %s=%f * %d\n", str, fvalue, ivalue);
	fflush(stdout);
}
