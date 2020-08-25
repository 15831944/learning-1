/*
 * mmcat.c
 * implement the cat commadn using mmap and family
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void err_quit(char *msg);

int main(int argc, char *argv[]) {
	int fdin;
	char *src;
	struct stat statbuf;
	off_t len;
	/* open the input file and stdout */
	if(argc != 2)
		err_quit("usage: mmcat <file>\n");
	if((fdin = open(argv[1], O_RDONLY)) < 0)
		err_quit("open failed");
	/* need the size of the input file for mmap() call */
	if (fstat(fdin, &statbuf) < 0)
		err_quit("fstat failed");
	len = statbuf.st_size;
	/* map the input file */
	if ((src = mmap(0,len, PROT_READ, MAP_SHARED, fdin, 0)) == (void *)-1)
		err_quit("mmap failed");
	/* write it out*/
	fprintf(stdout,"%s", src);

	/* clean up */
	close(fdin);
	munmap(src, len);
	exit(0);
}

void err_quit(char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}
