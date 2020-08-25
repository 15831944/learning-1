/*
 * color.c
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

	int n;
	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	if(has_colors()) {
		if (start_color() == ERR) {
			endwin();
			perror("start_color()");
			exit(1);
		}
		/* set up some simple color assignments */
		init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
		init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
		init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);

		for(n = 0; n <= 8; n++) {
			attron(COLOR_PAIR(n));
			printw("color pair %d in NORMAL mode\n", n);
			attron(COLOR_PAIR(n) | A_STANDOUT);
			printw("color pair %d in STANDOUT mode\n", n);
			attroff(A_STANDOUT);
			refresh();
		}
		sleep(10);
	} else {
		printw("Terminal does not support color\n");
		refresh();
		sleep(3);
	}
	endwin();
	exit(0);
}
