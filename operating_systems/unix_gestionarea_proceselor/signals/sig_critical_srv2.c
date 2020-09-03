/*
 * sig_critical_srv2.c
 * Critical region uninterupted in SRV2, same calls are interrupted and restarted.
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common/hdr.h"


jmp_buf jmpbuf;
int in_reg, sunt_in_reg;

void beg_reg(), end_reg();
void sig_int(int);

int read_line(char *);

int main()
{
	int nr_car;
	char buff[MAXLINE];

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("Error signal(SIGINT,...)");
	if(setjmp(jmpbuf)) {
		printf("The program is interrupted using signal\n");
		exit(1);
	}
	else
		while(1) {
			beg_reg();
			nr_car = read_line(buff);
			if (nr_car > 0)
				printf("%s\n", buff);
			else
				break;
			end_reg();
		}
	printf("Program is terminated normally! \n");
	exit(0);
}

void sig_int(int sig)
{
	if (in_reg) {
		signal(SIGINT, SIG_IGN);
		sunt_in_reg = 1;
		return;
	}
	else {
		signal(SIGINT, sig_int);
		longjmp(jmpbuf, 1);
	}
	return;
}

void beg_reg(void)
{
	in_reg =1;
	sunt_in_reg = 0;
}

void end_reg(void)
{
	in_reg  =0;
	if (sunt_in_reg) {
		sunt_in_reg = 0;
		signal(SIGINT, sig_int);
		longjmp(jmpbuf,1);
	}
}
int read_line(char *buff)
{
	char c;
	int i = 0;
	for(c = getchar(); i < MAXLINE && c != '\n'; c = getchar())
		buff[i++] = c;
	buff[i] = '\0';
	return i;
}
