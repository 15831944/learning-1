/*
 * curschar.c
 *
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
	addch('X');
	addch('Y' | A_REVERSE);
	mvaddch(2,1,'Z' | A_BOLD);
	refresh();
	sleep(3);
	clear();
	waddch(stdscr,'X');
	waddch(stdscr,'Y' | A_REVERSE);
	mvwaddch(stdscr,2,1,'Z' | A_BOLD);
	refresh();
	sleep(3);
	endwin();
}
