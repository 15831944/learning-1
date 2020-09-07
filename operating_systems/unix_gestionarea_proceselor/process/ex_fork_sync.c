/*
 * ex_fork.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <stdlib.h>
#include "../common/hdr.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void test(char *);

void config()
{
	int fd;
	if ((fd = creat("@@sincron@@",0)) == -1)
		err_sys("Open error");
	printf("The file @@sincron@@ has been created\n");
	return;
}

void Tell_F(pid_t pid)
{
	int fd;
	printf("Now the child process could be executed: %d\n", pid);
	if (unlink("@@sincron@@") == -1)
		err_sys("Unlink error");
}

void Wait_P()
{
	int fd;
	while((fd= creat("@@sincron@@", 0)) == -1 && errno == EACCES);
	if (fd == -1 || close(fd) == -1)
		err_sys("Creat() errror");
	unlink("@@sincron@@");
}
int main(void)
{
	pid_t pid;
	config();
	printf("Parent process has pid=%d\n",getpid());
	switch (pid = fork()) {
	case -1:
		err_sys("Fork error");
		break;
	case 0:
		Wait_P();
		test("Child has written\n");
		break;
	default:
		test("Parent has written\n");
		Tell_F(pid);
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
