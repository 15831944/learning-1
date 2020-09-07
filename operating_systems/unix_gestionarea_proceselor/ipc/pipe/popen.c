/*
 * popen.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#include "../../common/hdr.h"

static pid_t *childpid = NULL;
static int maxfd;

#define SHELL "/bin/sh"

FILE *popen(const char *cmd, const char *type)
{
	int pfd[2], i;
	pid_t pid;
	FILE *fp;
	printf(" P O P E N \n");
	if ((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
		errno = EINVAL;
		return NULL;
	}

	if (childpid == NULL) {
		//alocate memory to the child pids
		maxfd = sysconf(_SC_OPEN_MAX);
		if ((childpid = calloc(maxfd, sizeof(pid_t))) == NULL)
			return NULL;
	}
	if (pipe(pfd) < 0)
		return NULL;
	if ((pid = fork()) < 0)
		return NULL;
	else
		if (pid == 0) {
			if (*type == 'r') {
				close(pfd[0]);
				if (pfd[1] != 1) {
					dup2(pfd[1], 1);
					close(pfd[1]);
				}
			}
			else
			{
				close(pfd[1]);
				if (pfd[0] != 0) {
					dup2(pfd[0], 0);
					close(pfd[0]);
				}
			}
			//close all descriptors from childpid[]
			for (i = 0; i < maxfd; i++)
				if (childpid[i] > 0)
					close(i);
			execl(SHELL, "sh", "-c", cmd, NULL);
			exit(127);
		}
	if (*type == 'r') {
		close(pfd[1]);
		if ((fp = fdopen(pfd[0], type)) == NULL)
			return NULL;
	}
	else {
		close(pfd[0]);
		if ((fp = fdopen(pfd[1], type)) == NULL)
			return NULL;
	}
	childpid[fileno(fp)] = pid;
	return fp;
}

int pclose(FILE *fp)
{
	int fd, stat;
	pid_t pid;
	printf(" P C L O S E \n");
	if (childpid == NULL)
		return -1;
	fd =fileno(fp);
	if ((pid = childpid[fd]) == 0)
		return -1;//popen wasn't called before

	childpid[fd] = 0;
	if (fclose(fp) == EOF)
		return -1; //fp was not open by popen
	while(waitpid(pid, &stat, 0) < 0)
		if (errno != EINTR)
			return -1;
	return stat;
}
