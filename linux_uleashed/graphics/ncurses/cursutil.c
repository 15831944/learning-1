/*
 * cursutil.c
 * doesn't work to move window and to get it back
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

	int xmax, ymax, n = 0;
	WINDOW *pwin;
	FILE *fdump;

	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}

	if (!has_colors()) {
		printw("Terminal doesn't support color\n");
		refresh();
		sleep(3);
		endwin();
		exit(1);
	}
	if(start_color() == ERR) {
		endwin();
		perror("start_color()");
		exit(1);
	}
	init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);

	bkgd('#' | COLOR_PAIR(COLOR_RED));
	refresh();
	sleep(3);

	if((pwin = subwin(stdscr,10, 10, 0,0)) == NULL) {
		endwin();
		perror("subwin");
		exit(1);
	}
	wbkgd(pwin, '@' | COLOR_PAIR(COLOR_YELLOW));
	wrefresh(pwin);
	sleep(1);

	getmaxyx(stdscr, ymax, xmax);
	n = 0;
	while(n < (xmax - 10)) {
		if (mvwin(pwin, (ymax - 10)/2, n) == ERR) {
			printw("Could not move window to : %d %d\n", (ymax-10)/2,n);
			break;
		}
		refresh();
//		sleep(1);
		if (n == ((xmax - 10)/2)) {
			/* dump the subwindow to a file */
			fdump = fopen("dump.win", "w");
			putwin(stdscr,fdump);
			fclose(fdump);
		}
		n += 10;
	}
	clear();
	bkgd(' '| COLOR_PAIR(COLOR_WHITE));
	refresh();
	sleep(3);
	delwin(pwin);
	fdump = fopen("dump.win","r");
	pwin = getwin(fdump);
	wrefresh(pwin);
	sleep(3);

	clear();
	bkgd(' '| COLOR_PAIR(COLOR_WHITE));
	mvprintw(1,1,"ERASE character: %s\n",unctrl(erasechar()));
	mvprintw(2,1,"KILL character: %s\n", unctrl(killchar()));
	mvprintw(3,1,"BAUDRATE(bps) : %d\n", baudrate());
	mvprintw(4,1,"TEMINAL type: %s\n", termname());
	refresh();
	sleep(5);

	delwin(pwin);
	endwin();
	exit(0);
}
