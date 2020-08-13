/*
 * cursbox.c
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

	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	getmaxyx(stdscr,ymax, xmax);

	mvaddch(0,0,ACS_ULCORNER);
	hline(ACS_HLINE, xmax - 2);
	mvaddch(ymax - 1, 0, ACS_LLCORNER);
	hline(ACS_HLINE, xmax - 2);
	mvaddch(0, xmax - 1, ACS_URCORNER);
	vline(ACS_VLINE, ymax - 2);
	mvvline(1, xmax  -1, ACS_VLINE, ymax - 2);
	mvaddch(ymax - 1, xmax - 1, ACS_LRCORNER);
	mvprintw(ymax/3 - 1, (xmax - 30)/2, "border drawn the hard way");
	refresh();
	sleep(3);

	clear();
	box(stdscr, ACS_VLINE, ACS_HLINE);
	mvprintw(ymax/3 - 1, (xmax - 30)/2,"border drawn the easy way");
	refresh();
	sleep(3);

	clear();
	wborder(stdscr, ACS_VLINE | A_BOLD, ACS_VLINE | A_BOLD, ACS_HLINE | A_BOLD, ACS_HLINE | A_BOLD,
			ACS_ULCORNER | A_BOLD, ACS_URCORNER | A_BOLD, ACS_LLCORNER | A_BOLD, ACS_LRCORNER | A_BOLD);
	mvprintw(ymax/3 - 1, (xmax - 25)/2, "border drawn with wborder");
	refresh();
	sleep(3);
	endwin();
	exit(0);
}
