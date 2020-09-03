/*
 * ex_fork.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <stdlib.h>
#include "../common/hdr.h"

static void test(char *);
int main(void)
{
	pid_t pid;
	switch (pid = fork()) {
	case -1:
		err_sys("Fork error");
		break;
	case 0:
		test("Child has written\n");
		break;
	default:
		test("Parent has written\n");
		break;
	}
	exit(0);
}

static void test(char * s)
{
	char *pc;
	int c;
	setbuf(stdout, NULL);
	for(pc=s;  c = *pc++;) {
		putc(c, stdout);
		sleep(1.99999);
	}
}
