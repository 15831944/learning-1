/*
 * readfile_pipe.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../common/hdr.h"

#define DEF_PAGER "/bin/more"

int main(int argc, char *argv[])
{
	int pfd[2], n;
	pid_t pid;
	char buf[MAXLINE], *pager, *arg;
	FILE *fp;

	if (argc != 2)
		err_quit("Usage: %s <path>\n", argv[0]);
	if (pipe(pfd) < 0)
		err_sys("Pipe error");
	if ((fp = fopen(argv[1], "r")) == NULL)
		err_sys("Could not open file %s", argv[1]);
	switch(fork()) {
	case -1:
		err_sys("Fork error");
		break;
	case 0:
		close(pfd[1]);
		if (pfd[0] != 0) {
			if (dup2(pfd[0],0) != 0)
				err_sys("Error dup2");
			close(pfd[0]);
		}
		if ((pager = getenv("PAGER")) == NULL)
			pager = DEF_PAGER;
		if ((arg = strrchr(pager, '/')) != NULL)
			arg++;
		else
			arg = pager;
		if (execl(pager, arg, NULL) < 0)
			err_sys("Error execl to %s", pager);
		break;
	default:
		close(pfd[0]);
		while(fgets(buf, MAXLINE, fp) != NULL) {
			n = strlen(buf);
			if (write(pfd[1], buf, n) != n)
				err_sys("Write error");
		}
		if (ferror(fp))
			err_sys("Ferror error");
		close(pfd[1]);
		if (waitpid(pid, NULL, 0) < 0)
			err_sys("Waitpid error");
		exit(0);
	}
}
