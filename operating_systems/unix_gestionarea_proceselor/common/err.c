/*
 * err.c
 * rutine de tratare a errorilor
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <errno.h>
#include <stdarg.h>

#include "hdr.h"

static void err_do(int, const char *, va_list);

char *pname = NULL;

/*
 * fatal error because of system call
 * print the message and terminate the process
 */
void err_sys(const char *frmt, ...)
{
	va_list ap;
	va_start(ap, frmt);
	err_do(1, frmt, ap);
	va_end(ap);
	exit(1);
}

/*
 * not fatal error because of system call
 * print the message and return
 */
void err_ret(const char *frmt,...)
{
	va_list ap;
	va_start(ap, frmt);
	err_do(1,frmt,ap);
	va_end(ap);
	return;
}

/*
 * fatal error independent of the system call
 * print the message and terminate process
 */
void err_quit(const char *frmt,...)
{
	va_list ap;
	va_start(ap, frmt);
	err_do(0,frmt, ap);
	va_end(ap);
	exit(1);
}

/*
 * not fatal error independent of system call
 * print the message and return
 */

void err_msg(const char *frmt, ...)
{
	va_list ap;
	va_start(ap, frmt);
	err_do(0, frmt, ap);
	va_end(ap);
	return;
}

/*
 * fatal error relative to system call
 * print the mesage, dump core and terminate the process
 */
void err_dump(const char *frmt, ...)
{
	va_list ap;
	va_start(ap, frmt);
	err_do(1, frmt, ap);
	va_end(ap);
	abort(); // dump core
	exit(1);
}

static void err_do(int errfan, const char *frmnt, va_list ap)
{
	int errno_save;
	char buf[MAXLINE];
	errno_save = errno;
	vsprintf(buf, frmnt, ap);
	if(errfan)
		sprintf(buf + strlen(buf), ": %s", strerror(errno_save));
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);
	return;
}
