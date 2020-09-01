/*
 * printIds.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	exit(0);
}
