/*
 * canary.c
 * example of how to use canary values
 * new system don't need this the system autodetect
 * *** stack smashing detected ***: <unknown> terminated
 *  Created on: Aug 15, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int canary_value = 0x12345678;

void function() {
	int canary;
	char overfloable[12];
	canary = canary_value;
	printf("type some text: ");
	gets(overfloable);
	assert(canary == canary_value);
	return;
}

int main() {
	function();
	exit(0);
}
