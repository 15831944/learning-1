/*
 * error.c
 * run as error < input | error | error > output
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <errno.h>
#include "../common/hdr.h"

int main(int argc, char *argv[])
{
	int fd=8, no = 5;
	char buf[5];
	fprintf(stderr,"EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	if (read(fd, buf, no) == -1)
		err_sys("Read error");
	exit(0);
}
