/*
 * mask_log.c
 * demonstrate openlog and family
 * in modern one the log is syslog and not into messages from /var/log
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	int ret;
	openlog("mask_log", LOG_PID, LOG_USER);
	syslog(LOG_INFO, "This message courtesy of UID #%d\n", getuid());
	syslog(LOG_NOTICE, "Hopefully, you see this.\n");
	/* dont' want to see DEBUG and INFO messages */
	ret = setlogmask(LOG_UPTO(LOG_NOTICE));
	syslog(LOG_INFO,"You should not be seeing this\n");
	syslog(LOG_DEBUG,"I hope you don't see this\n");
	syslog(LOG_NOTICE,"This should still appear\n");
	closelog();
	exit(EXIT_SUCCESS);
}
