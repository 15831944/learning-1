/*
 * filefcn.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>
#include "filefcn.h"

int open_file(FILE *fp, char *fname, char *mode, int line,
char *file) {
	if ((fp = fopen(fname, mode)) == NULL) {
		fprintf(stderr, "[%s:%d] open_file failed\n", file, line);
		return 1;
	}
	return 0;
}
