/*
 * filefcn.h
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#ifndef FILEFCN_H_
#define FILEFCN_H_
#include <stdio.h>

int open_file(FILE *fp, char *fname, char *mode,
		int line, char *file);

#endif /* FILEFCN_H_ */
