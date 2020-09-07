/*
 * fsort.c
 * filter which sort input text
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <stdio.h>
#include <fcntl.h>
#include "../../common/hdr.h"

void fsort(char *path);

int main(int argc, char *argv[])
{
	if (argc < 2)
		err_quit("Usage: %s <file.txt>\n", argv[0]);
	fsort(argv[1]);
}

void fsort(char *path)
{
	int pfdout[2], pfdin[2], fd, nr;
	char buf[512];

	if (pipe(pfdout) < 0 || pipe(pfdin) < 0)
		err_sys("Pipe error");
	switch(fork()) {
	case -1:
		err_sys("Fork error");
		break;
	case 0:
		if (close(pfdin[0]) < 0 || close(pfdout[1]) < 0)
			err_sys("Error on close unused");
		if (close(0) < 0)
			err_sys("Error on close stdin");
		if (dup(pfdout[0]) != 0)
			err_sys("Error dup on stdin");
		if (close(1) < 0)
			err_sys("Error on close stdout");
		if (dup(pfdin[1]) != 1)
			err_sys("Error dup on stdout");
		//we free the used descriptors
		if (close(pfdout[0]) < 0 || close(pfdin[1]) < 0)
			err_sys("Close error");
		execlp("sort","sort", NULL);
		err_sys("Error execlp");
	}
	if (close(pfdout[0]) < 0 || close(pfdin[1]) < 0)
		err_sys("Parent: error clsoe unused");
	if ((fd = open(path, 0)) < 0)
		err_sys("Error open");
	//write unsorted data into the pipe
	while((nr = read(fd, buf, sizeof(buf))) != 0) {
		if (nr < 0)
			err_sys("Read error - unsorted data");
		if (write(pfdout[1], buf, nr) < 0)
			err_sys("Write error - unsorded data");
	}
	if (close(fd) < 0 || close(pfdout[1]) < 0)
		err_sys("Close error: DATA & pfdout[1]");
	//read data from pipe
	while((nr = read(pfdin[0], buf, sizeof(buf))) != 0) {
		if (nr < 0)
			err_sys("Read error - sorted data");
		if (write(1, buf, nr) < 0)
			err_sys("Write error - sorted data");
	}
	if (close(pfdin[0]) == -1)
		perror("close");
}
