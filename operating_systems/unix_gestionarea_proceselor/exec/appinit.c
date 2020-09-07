/*
 * appinit.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "execs.h"

#define WT_MASK (0x7F)
#define WT_EXITED (0x00)
#define WT_STOPPED (0x7F)
#define WT_CORE (0x80)
#define WT_BITS (8)
#define MAXLINE 128

void aps(int pidc, int pidv[], char *ttyv[], char *cmdlinv[])
{
	int i;
	printf("TTYCOMMAND PID\n");
	for(i = 0; i < pidc; i++) {
		printf("%-6s %-25s", ttyv[i]+5, cmdlinv[i]);
		if (pidv[i] != 0)
			printf(" %5d\n", pidv[i]);
		else
			printf("<ended>\n");
	}
}

int main(int argc, char *argv[])
{
	struct termio ttyparms;
	int pidc = 0; //counting process
	int *pidv= NULL; //pid vector
	char **ttyv = NULL; //device vector
	char **cmdlinv = NULL;
	int pid = 0;
	int status = 0;
	int i = 0;
	int k;
	char *p = NULL;
	char c;
	char lin[MAXLINE];
	char **linia;
	// read configuration file
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		printf("Could not open configuration file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ttyv = NULL;
	for(k = 0; ; k++) {
		if (read(fd,&c,1) == 0) break;
		lseek(fd,-1,1);
		while(read(fd,&c,1) > 0) {
			if (c == '\n') break;
			lin[i++] = c;
		}
		lin[i] = '\0';
		linia = (char **)realloc(linia, (size_t)((k+1)*sizeof(*linia)));
		linia[k] = (char *)calloc((size_t)(strlen(lin) + 1), sizeof(*lin));
		strcpy(linia[k], lin);
		p = strtok(linia[k], " ");
		i = 0;
		ttyv= (char **)realloc(ttyv, (size_t)((pidc + 1)*sizeof(*ttyv)));
		if (p == NULL) {
			ttyv[pidc] = NULL;
			printf("Missing device in line %d\n", pidc -1);
			break;
		}

		ttyv[pidc] = (char *)calloc((size_t)(strlen(p) + 1), sizeof(*ttyv[pidc]));
		strcpy(ttyv[pidc++], p);
		// take command line
		p = strtok(NULL, "");
		if (p == NULL) {
			cmdlinv[k] = NULL;
			printf("Missing command in line %d\n", pidc -1);
			break;
		}
		cmdlinv = (char **)realloc(cmdlinv, (size_t)((k+1)*sizeof(*cmdlinv)));
		cmdlinv[k] = (char *)calloc((size_t)(strlen(p) + 1), sizeof(*cmdlinv[k]));
		strcpy(cmdlinv[k], p);
	}
	pidv = (int *)calloc((size_t)(pidc), sizeof(*pidv));
	ioctl(0, TCGETA, &ttyparms);
	for(i = 0; i < pidc; i++) {
		pidv[i] = fork();
		switch(pidv[i]) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;
		case 0:
			printf("child:%d\n", pidv[i]);
			setpgrp();
			if (strcmp(ttyv[i], "/dev/null") != 0) {
				close(0);
				if (open(ttyv[i], O_RDONLY) == -1) {
					perror("Opening stdin");
					exit(EXIT_FAILURE);
				}
				close(1);
				if (open(ttyv[i], O_WRONLY) == -1) {
					perror("Opening stdout");
					exit(EXIT_FAILURE);
				}
				close(2);
				if (open(ttyv[i], O_WRONLY) == -1) {
					exit(EXIT_FAILURE);
					ioctl(0, TCSETAF, &ttyparms);
				}
			}
			execs(cmdlinv[i]);
			perror("execs");
			exit(EXIT_FAILURE);
			break;
		default:
			printf("Executing process %d on %s.\n", pidv[i], ttyv[i]);
			continue;
			break;

		}
	}
	//monitor child processes
	for (;;) {
		putchar('\n');
		aps(pidc, pidv, ttyv, cmdlinv);
		putchar('\n');
		pid = wait(&status);
		printf("Value returned by wait: %d\n", pid);
		if (pid == -1) {
			if (errno == ECHILD) {
				printf("All child processes has been ended.\n");
				break;
			}
			perror("wait");
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < pidc; i++) {
			if (pidv[i] == pid) {
				pidv[i] = 0;
				break;
			}
		}
		if (i >= pidc) continue; //unknown child
		printf("%s", ttyv[i]);
		switch(status & WT_MASK) {
		case WT_EXITED:
			printf("Process %d has been ended with exit(%d).\n", pid, status >> WT_BITS);
			break;
		case WT_STOPPED:
			printf("Process %d had been stopped with signal %d.\n", pid, status >> WT_BITS);
			break;
		default:
			printf("Process %d has been terminated because signal %d.\n", pid, status & WT_MASK);
			if (status & WT_CORE)
				printf("Core file has been generated.\n");
			printf("\n");
			break;
		}
	}
	exit(EXIT_SUCCESS);
}
