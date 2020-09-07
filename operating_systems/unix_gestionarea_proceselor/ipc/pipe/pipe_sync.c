/*
 * sigsuspend2.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include "../../common/hdr.h"
#include "sync.h"

static void test(char *);

int main(void)
{
	pid_t pid;
	config();
	switch (pid = fork()){
	case -1:
		err_sys("Fork Error");
		break;
	case 0:
			Wait_P();
			test("The child has written!\n");
			break;
	default:
		test("The parent has written!\n");
		Tell_F(pid);
		break;
	}
	exit(0);
}

static void test(char *s)
{
	char *pc;
	int c;
	setbuf(stdout, NULL);
	for(pc = s; c=*pc++;) {
		putc(c,stdout);
		sleep(0.5);
	}
}
