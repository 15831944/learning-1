/*
 * mem.c
 * demonstrating allocation functions
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err_quit(char *);
void prn(char *,char *, int);

int main(void) {
	char *c,*d,*e;

	if((c = malloc(10)) == NULL)
		err_quit("malloc() failed");
	prn("malloc", c, 10);
	free(c);

	if((d = calloc(10,1)) == NULL)
		err_quit("calloc() failed");
	prn("calloc",d, 10);
	strcpy(d,"foobar");
	fprintf(stdout,"d = %s\n", d);
	if((d = realloc(d,20)) == NULL)
		err_quit("realloc() failed");
	fprintf(stdout,"d = %s\n",d);
	prn("realloc",d,20);
	if((e = alloca(10)) == NULL)
		err_quit("alloca() failed");
	prn("alloca",e,10);
	exit(0);
}

void err_quit(char *msg) {
	fprintf(stderr,"%s\n",msg);
	exit(EXIT_FAILURE);
}

void prn(char *memop,char *str, int len) {
	int i;
	fprintf(stdout,"%8s :", memop);
	for(i = 0; i< len; i++)
		fprintf(stdout,"%d ",str[i]);
	fprintf(stdout,"\n");
}


