/*
 * newterm.c
 * curses initialization and termination
 *  Created on: Aug 12, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdlib.h>
#include <curses.h>
#include <error.h>
#include <unistd.h>

int main(void) {
	SCREEN *scr;
	if((scr = newterm(NULL, stdout, stdin)) == NULL) {
		perror("newterm");
		exit(EXIT_FAILURE);
	}

	if(set_term(scr) == NULL) {
		perror("set_term");
		endwin();
		delscreen(scr);
		exit(EXIT_FAILURE);
	}

	printw("This curses window created with newterm()\n");
	refresh();
	sleep(3);

	printw("Going bye-bye now\n");
	refresh();
	sleep(3);
	endwin();
	delscreen(scr);
	exit(0);
}
