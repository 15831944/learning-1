/*
 * finalApp.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../common/hdr.h"

int fd, semaf=1,idpf, idpp;

char buff[20];

static void sincro(int);
static int desch(char *);
static int preia_date(int);

int main()
{
	idpp = getpid();
	signal(SIGUSR1, sincro);
	signal(SIGFPE, sincro);

	switch(idpf = fork()) {
	case -1:
		err_sys("Error fork 1");
		break;
	case 0:
		switch(idpf = fork()) {
		case -1:
			err_sys("Error fork 2");
			break;
		case 0:
			//second read note
			fd = desch("note.txt");
			while(semaf == 1) pause();
			while(preia_date(fd)) {
				printf("%s\n", buff);
				semaf = 1;
				kill(idpp, SIGUSR1);
				while(semaf == 1)
					pause();
			}
			kill(idpp, SIGFPE);
			exit(0);
		default:
			//first child read materia
			fd = desch("mate.txt");
			while(semaf == 1)
				pause();
			while(preia_date(fd)) {
				printf("%s\t", buff);
				fflush(stdout);
				semaf = 1;
				kill(idpf, SIGUSR1);
				while(semaf == 1)
					pause();
			}
			kill(idpf, SIGFPE);
			exit(0);
		}
		default:
			//parent process
			fd = desch("nume.txt");
			while(preia_date(fd)) {
				printf("%s\t", buff);
				fflush(stdout);
				semaf = 1;
				kill(idpf, SIGUSR1);
				while(semaf == 1)
					pause();
			}
			kill(idpf, SIGFPE);
			exit(0);
	}
}

static void sincro(int sig)
{
	switch(sig) {
	case SIGUSR1:
		signal(SIGUSR1, sincro);
		semaf = 0;
		break;
	case SIGFPE:
		kill(idpf, SIGTERM);
		exit(0);
	}
}

static int desch(char *path)
{
	register int fd;
	if ((fd  = open(path,0)) < 0)
		err_quit("Could not open file: %s\n", path);
	return fd;
}

static int preia_date(int fis)
{
	char c, n;
	do
		n = read(fis, &c, 1);
	while(n==1 && (c == ' ' || c == '\n' || c == '\r'));
	if (n == 0)
		return 0;
	n = 0;
	buff[n++] = c;
	while(read(fis, &c, 1) && c != ' ' && c != '\n' && c != '\r')
		buff[n++] = c;
	buff[n] = '\0';
	return 1;
}
