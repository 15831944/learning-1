/*
 * initcurs.c
 * curses initialization and termination
 *  Created on: Aug 12, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdlib.h>
#include <curses.h>
#include <errno.h>
#include <unistd.h>

int main(void) {
	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	printw("This is a curses window\n");
	refresh();
	sleep(3);

	printw("Going by-by now\n");
	refresh();
	sleep(3);
	endwin();

	exit(0);
}
