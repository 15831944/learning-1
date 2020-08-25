/*
 * errs.c
 * demonstrate perror and strerror
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int main() {
	double d;
	errno = 0;
	d = sqrt(-1);
	if(errno) fprintf(stderr,"sqrt: %s\n",strerror(errno));
	errno = 0;
	d = sqrt(-2);
	if(errno) perror("sqrt");
	exit(EXIT_SUCCESS);
}
