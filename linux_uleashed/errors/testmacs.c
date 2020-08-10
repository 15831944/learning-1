/*
 * testmacs.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>
#include "filefcn.h"

int main(void) {
	FILE *fp;
	int ret;

	if(open_file(fp, "foo_bar", "w", __LINE__, __FILE__))
		exit(EXIT_FAILURE);
	if (fp) fclose(fp);
	ret = open_file(fp,"bar_baz","r", __LINE__,__FILE__);
	if(ret) exit(EXIT_FAILURE);
	if (fp) fclose(fp);
	return 0;
}

