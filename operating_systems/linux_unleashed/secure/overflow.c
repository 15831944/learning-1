/*
 * overflow.c
 * a simple buffer overflow program
 *  Created on: Aug 15, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	char command[80] = "date";
	char name[20];

	printf("Please enter your name: ");
	gets(name);
	printf("Hello, %s, the curent date and time is: ", name);
	fflush(stdout);
	system(command);
	exit(0);
}
