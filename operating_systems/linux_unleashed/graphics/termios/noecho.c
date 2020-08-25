/*
 * noecho.c
 *
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#define PASS_LEN 8

void err_quit(char *msg, struct termios flags);

int main() {
	struct termios old_flags, new_flags;
	char password[PASS_LEN + 1];
	int retval;

	/* get the current teminal settings */
	tcgetattr(fileno(stdin), &old_flags);
	new_flags = old_flags;
	/* turn off local echo, but pass the newline */
	new_flags.c_lflag &= ~ECHO;
	new_flags.c_lflag |= ECHONL;

	retval = tcsetattr(fileno(stdin), TCSAFLUSH, &new_flags);
	if (retval != 0)
		err_quit("Failed to set attributes", old_flags);

	tcgetattr(fileno(stdin), &new_flags);
	if (new_flags.c_lflag & ECHO)
		err_quit("Failed to turn off ECHO", old_flags);
	if(!new_flags.c_lflag & ECHONL)
		err_quit("Failed to tun on ECHONL", old_flags);

	fprintf(stdout,"Enter password: ");
	fgets(password,PASS_LEN + 1, stdin);
	fprintf(stdout,"You typed: %s\n", password);
	/*restore */
	tcsetattr(fileno(stdin), TCSAFLUSH, &old_flags);

	exit(EXIT_SUCCESS);
}

void err_quit(char *msg, struct termios flags) {
	fprintf(stderr, "%s\n", msg);
	tcsetattr(fileno(stdin), TCSANOW, &flags);
	exit(EXIT_FAILURE);
}
