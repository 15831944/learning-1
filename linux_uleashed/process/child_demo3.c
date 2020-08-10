/*
 * child_demo3.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <limits.h>

#include "child.h"

int debug = 5;
extern char **environ;

main(int argc, char *argv[]) {
	int count;
	int i;
	char **newargv;
	int rc;

	/* very primiteve exemple, borrows everything from the currecnt process */
	if (debug >= 5) child_print_arg_array("argv",argv);

	fprintf(stderr,"argc=%d\n", argc);
	assert(argc >= 2);
	/* make new argv from argv */
	count = 0;
	while(1) {
		count++;
		if (argv[count] == NULL) break;
	}
	printf("count=%d\n", count);
	newargv = malloc(sizeof(void *)*(count + 2));
	newargv[0] = argv[1];
	for(i = 1; i < count; i++) {
		newargv[i] = argv[i+1];
	}
	newargv[i] = NULL;
	printf("argv[1] = %s\n",argv[1]);
	if (debug>=5) child_print_arg_array("newargv",newargv);
	if (debug >= 5) child_print_arg_array("environ", environ);

	fprintf(stderr,"invoking program\n");
	rc = child_pipeve(argv[1], newargv, environ, NULL, NULL, NULL);
	fprintf(stderr, "program invocation over\n");

	fprintf(stderr,"rc = %d\n", rc);
	if (rc < 0) {
		perror("child_pipev()");
	}
}
