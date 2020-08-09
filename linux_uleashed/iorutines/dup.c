/*
 * dup.c
 *
 *  Created on: Aug 7, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

void print_line(int n)
{
	char buf[32];
	snprintf(buf, sizeof(buf), "Line #%d\n",n);
	write(1, buf, strlen(buf));
}
void main()
{
	int fd;
	print_line(1);
	print_line(2);
	print_line(3);

	/* redirect stdout to file junk.out */
	fd = open("junk.out", O_WRONLY | O_CREAT, 0666);
	assert(fd > 0);
	dup2(fd,1);

	print_line(4);
	print_line(5);
	print_line(6);

	close(fd);
	close(1);
}
