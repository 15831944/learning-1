/*
 * liberr.h
 *
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#ifndef _LIBERR_H_
#define _LIBERR_H_

#include <stdarg.h>

#define MAXLINELEN 4096

/*
 * print an error message to stderr and return to caller ...
 */
void err_ret(const char *fmt, ...);

/*
 * print an error message to stderr and exit
 */
void err_quit(const char *fmt, ...);

/*
 * print an error message to logfile and return to caller
 */
void log_ret(char *logfile, const char *fmt, ...);

/*
 * print an error message to logfile and exit
 */
void log_quit(char *logfile, const char *fmt, ...);

/*
 * print an error message and return to caller
 */
void err_prn(const char *fmt, va_list ap, char *logfile);

#endif /* _LIBERR_H_ */
