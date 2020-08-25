/*
 * new_getcaps.c
 * get and show terminal capabilities using terminfo
 *  Created on: Aug 12, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>

#define NUMCAPS 3

void clrscr(void);
void mv_cursor(int,int);

int main(void) {
	int i;
	int retval = 0;
	char *buf;
	char *boolcaps[NUMCAPS] = {"am", "bce", "km"};
	char *numcaps[NUMCAPS] = {"cols", "lines", "colors"};
	char *strcaps[NUMCAPS] = {"cup", "flash", "hpa"};

	if(setupterm(NULL, fileno(stdin), NULL) != OK) {
		perror("setupterm()");
		exit(EXIT_FAILURE);
	}
	clrscr();
	for(i = 0; i < NUMCAPS; ++i) {
		/* position of the cursor */
		mv_cursor(i,10);
		retval = tigetflag(boolcaps[i]);
		if (retval == FALSE)
			printf ("`%s' unsupported\n", boolcaps[i]);
		else
			printf ("`%s' supported\n", boolcaps[i]);
	}
	sleep(3);

	clrscr();
	for(i = 0; i < NUMCAPS; ++i) {
		mv_cursor(i, 10);
		retval = tigetnum(numcaps[i]);
		if (retval == ERR)
			printf ("`%s' unsupported\n", numcaps[i]);
		else
			printf ("`%s' is %d\n", numcaps[i], retval);
	}
	sleep(3);

	clrscr();
	for(i = 0; i < NUMCAPS; ++i) {
		mv_cursor(i,10);
		buf = tigetstr(strcaps[i]);
		if (buf == NULL)
			printf ("`%s' unsupported\n", strcaps[i]);
		else
			printf ("`%s' is \\E%s\n", strcaps[i], &buf[1]);
	}
	sleep(3);
	exit(0);
}

/* clear the screen */
void clrscr() {
	char *buf = tigetstr("clear");
	putp(buf);
}

/* move the cursor to the specified row and column */
void mv_cursor(int row, int col) {
	char *cap = tigetstr("cup");
	putp(tparm(cap,row, col));
}
