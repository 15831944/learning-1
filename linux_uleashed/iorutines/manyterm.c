/*
 * manyterm.c
 * select based terminal program
 *  Created on: Aug 7, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

/*
 * crude terminal program
 * - does not lock modem
 * - does not disable echo on users terminal
 * - does not put terminal in raw node
 * - control-c will abort
 */
int debug = 0;
void dump_fds(char *name, fd_set *set, int max_fd)
{
	int i;
	if(!debug) return;
	fprintf(stderr, "%s:", name);
	for (i = 0; i<max_fd; i++) {
		if (FD_ISSET(i, set)) {
			fprintf(stderr, "%d,",i);
		}
	}
	fprintf(stderr,"\n");
}

void main()
{
	int keyboard;
	int screen;
	int serial;
	char c;
	int rc;
	struct termios tio;
#ifndef BADCODE
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;
	struct timeval tv;
	int max_fd;
	/*
	 * inbound and outbound keep track of whether we have a character
	 * already read which needs to be sent in that direction
	 * the _char variables are the data buffer
	 */
	int outbound;
	char outbound_char;
	int inbound;
	char inbound_char;
#endif

	keyboard = open("/dev/tty", O_RDONLY | O_NONBLOCK);
	assert(keyboard >= 0);
	screen = open("/dev/tty", O_WRONLY | O_NONBLOCK);
	assert(screen >= 0);
	serial = open("/dev/tty", O_RDWR | O_NONBLOCK);
	assert(serial >= 0);

	if (debug) {
		fprintf(stderr,"keyboard=%d\n", keyboard);
		fprintf(stderr,"screen=%d\n", screen);
		fprintf(stderr,"serial=%d\n",serial);
	}
#ifdef BADCODE
	while(1) {
		rc = read(keyboard,&c,1);
		if(rc == 1) {
			while(write(serial,&c,1) != 1)
				;
		}
		rc = read(serial,&c,1);
		if (rc == 1) {
			while(write(screen,&c,1) != 1)
				;
		}
	}
#else
	outbound = inbound = 0;
	while(1) {
		FD_ZERO(&writefds);
		if(inbound)
			FD_SET(screen,&writefds);
		if(outbound)
			FD_SET(serial,&writefds);
		FD_ZERO(&readfds);
		if(!outbound)
			FD_SET(keyboard,&readfds);
		if(!inbound)
			FD_SET(serial, &readfds);
		max_fd = 0;
		if(screen > max_fd)
			max_fd = screen;
		if(keyboard > max_fd)
			max_fd = keyboard;
		if(serial > max_fd)
			max_fd = serial;
		max_fd++;
		if(debug)
			fprintf(stderr,"max_fd=%d\n",max_fd);
		tv.tv_sec = 10;
		tv.tv_usec = 0;
		dump_fds("read in", &readfds, max_fd);
		dump_fds("write in",&writefds, max_fd);
		rc = select(max_fd,&readfds,&writefds, NULL, &tv);
		dump_fds("read out", &readfds, max_fd);
		dump_fds("write out",&writefds, max_fd);

		if(FD_ISSET(keyboard, &readfds)) {
			if(debug)
				fprintf(stderr,"\nreading outbound\n");
			rc = read(keyboard,&outbound_char,1);
			if(rc == 1)
				outbound = 1;
			if(outbound == 3)
				exit(0);
		}
		if(FD_ISSET(serial,&readfds)) {
			if(debug)
				fprintf(stderr,"\nreading inbound\n");
			rc = read(serial,&inbound_char,1);
			if (rc == 1)
				inbound = 1;
		}
		if (FD_ISSET(serial, &writefds)) {
			if(debug)
				fprintf(stderr,"\nwriting outbound\n");
			rc = write(serial,&outbound_char,1);
			if(rc == 1)
				outbound = 0;
		}
	}
#endif
}
