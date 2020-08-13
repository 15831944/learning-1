/*
 * cursinch.c
 * curses character input functions
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
	int c, i = 0;
	char str[80];
	WINDOW *pwin;

	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	crmode();
	getmaxyx(stdscr,ymax, xmax);
	if ((pwin = subwin(stdscr, 4, 40, ymax/3, (xmax-40)/2)) == NULL) {
		perror("subwin");
		endwin();
		exit(1);
	}
	box(pwin, ACS_VLINE, ACS_HLINE);
	mvwaddstr(pwin, 1, 1, "Password: ");
	noecho();
	while((c = getch()) != '\n' && i < 80) {
		str[i++] = c;
		waddch(pwin,'*');
		wrefresh(pwin);
	}
	echo();
	str[i] = '\0';
	wrefresh(pwin);
	mvwprintw(pwin, 1, 1, "You typed: %s\n",str);
	box(pwin, ACS_VLINE, ACS_HLINE);
	wrefresh(pwin);
	sleep(3);

	delwin(pwin);
	endwin();
	exit(0);
}
