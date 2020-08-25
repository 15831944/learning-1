/*
 * debugme.c
 *
 *  Created on: Aug 15, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>

#define BIGNUM 5000

void index_to_the_moon(int ary[]);

int main(void)
{
	int intary[10];
	index_to_the_moon(intary);
	exit(EXIT_SUCCESS);
}

void index_to_the_moon(int ary[])
{
	int i;
	for(i = 0; i < BIGNUM; i++)
		ary[i] = i;
}
