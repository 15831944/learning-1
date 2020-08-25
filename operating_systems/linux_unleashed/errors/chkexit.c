/*
 * chkexit.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>

void f_atexit(void) {
	fprintf(stdout,"Here we are in f_atexit()\n");
}

int main(int argc,char *argv[]) {
	fprintf(stdout, "Here we are in main()\n");
	if(atexit(f_atexit) != 0) {
		fprintf(stderr,"Failed to register f_atexit()\n");
	}
	fprintf(stdout,"Exiting ... \n");
	if(atoi(argv[1])) abort();
	return 0;
}
