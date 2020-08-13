/*
 * cursstr.c
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

	int xmax, ymax;
	WINDOW *tmpwin;

	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	getmaxyx(stdscr,ymax, xmax);
	addstr("Using the *str() family\n");
	hline(ACS_HLINE, xmax);
	mvaddstr(3,0,"This string appears in full\n");
	mvaddnstr(5, 0, "This string is trucated\n", 15);
	refresh();
	sleep(3);
	if((tmpwin = newwin(0,0,0,0)) == NULL) {
		perror("newwin");
		endwin();
		exit(0);
	}
	mvwaddstr(tmpwin, 1,1 , "This message should appear in a new window");
	wborder(tmpwin, 0,0,0,0,0,0,0,0);
	touchwin(tmpwin);
	wrefresh(tmpwin);
	sleep(3);
	delwin(tmpwin);
	endwin();
}
