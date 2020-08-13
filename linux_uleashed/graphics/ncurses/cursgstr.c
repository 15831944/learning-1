/*
 * cursgstr.c
 * curses string input functions
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
	char str[80];
	char *pstr;

	if((initscr()) == NULL) {
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	crmode();
	getmaxyx(stdscr,ymax, xmax);
	printw("File to open: ");
	refresh();
	getstr(str);
	printw("You typed: %s\n", str);
	refresh();
	sleep(3);

	if((pstr = malloc(sizeof(char)* 20)) == NULL) {
		endwin();
		perror("malloc");
		exit(1);
	}
	printw("Enter your name: ");
	refresh();
	getnstr(pstr,20);
	printw("You entered: %s\n", pstr);
	refresh();
	sleep(3);

	free(pstr);
	endwin();
	exit(0);
}
