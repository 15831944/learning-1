/*
 * badmem.c
 *
 *  Created on: Aug 9, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char g_buf[5];

int main(void) {
	char *buf;
	char *leak;
	char l_buf[5];

	/* won't free this */
	leak = malloc(10);
	buf = malloc(5);
	strcpy(buf,"abcd");
	printf("LITTLE : %s\n", buf);
	free(buf);

	buf = malloc(5);
	*(buf -2) = '\0';
	printf("UNDERRUN: %s\n", buf);

	free(buf);
	free(buf);

	strcpy(buf,"this will blow up");
	printf("FREED : %s\n", buf);
	strcpy(g_buf,"gloobal boom");
	printf("GLOBAL : %s\n", g_buf);
	strcpy(l_buf,"local boom");
	printf("LOCAL : %s\n", l_buf);
	exit(0);
}
