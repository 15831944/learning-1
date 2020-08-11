/*
 * liberr.c
 *
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */


#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liberr.h"

void err_ret(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_prn(fmt, ap, NULL);
	va_end(ap);
	return;
}

void err_quit(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_prn(fmt, ap, NULL);
	va_end(ap);
	exit(1);
}

void log_ret(char *logfile, const char *fmt, ... ) {
	va_list ap;
	va_start(ap, fmt);
	err_prn(fmt, ap, logfile);
	va_end(ap);
	return;
}

void log_quit(char *logfile, const char *fmt, ... ) {
	va_list ap;
	va_start(ap, fmt);
	err_prn(fmt, ap, logfile);
	va_end(ap);
	exit(1);
}

extern void err_prn(const char *fmt, va_list ap, char *logfile) {
	int save_err;
	char buf[MAXLINELEN];
	FILE *plf;

	save_err = errno;
	vsprintf(buf, fmt, ap);
	sprintf(buf + strlen(buf), ": %s", strerror(save_err));
	strcat(buf, "\n");
	fflush(stdout);
	if (logfile != NULL) {
		if ((plf = fopen(logfile, "a")) != NULL) {
			fputs(buf, plf);
			fclose(plf);
		} else {
			fputs("failed to open log file\n", stderr);
		}
	} else {
		fputs(buf, stderr);
	}
	fflush(NULL);
	return;
}

