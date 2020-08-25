/*
 * child_demo1.c
 *
 *  Created on: Aug 9, 2020
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
#include "child.h"

void child_process_1(child_info_t *child_info_p, void *private_p) {
	int rc;
	int sleep_time;
	assert(child_info_p);
	/* undo signal settings from parent */
	signal(SIGTERM,SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT,SIG_DFL);

	/* this is child process */
	fprintf(stderr,"Child process #%d starting, pid = %d, parent = %d\n", child_info_p->number, child_info_p->pid, child_info_p->ppid);
	/* usefull work */
	sleep_time = random() & 0x7F;
	fprintf(stderr,"Child process #%d sleeping for %d seconds\n", child_info_p -> number, sleep_time);
	sleep(sleep_time);
	fprintf(stderr,"Child process #%d exiting, pid = %d, parent = %d\n", child_info_p -> number, child_info_p -> pid, child_info_p -> ppid);
}

child_group_info_t child_group_1;

jmp_buf jump_env;

void sig_handler(int signal) {
	fprintf(stderr, "pid %d received signal %d\n", getpid(), signal);
	child_restart_children = 0;
#if 0
	/* wake up the wait() doesn't work */
	raise(SIGCHLD);
#endif
	longjmp(jump_env, 1);
}

void main() {
	int i;
	int child;
	child_group_info_t child_group_1;
	child_groups_t child_groups;
	int rc;
#if 0
	setvbug(stderr, NULL, _IOLBF, 0);
#else
	setbuf(stderr, NULL);
#endif
	/* note children inherit this */
	signal(SIGTERM, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	child_group_create(&child_group_1, 4, 4, child_process_1, NULL);
	child_groups.ngroups = 1;
	child_groups.group[0] = &child_group_1;

	rc = setjmp(jump_env);
	if (rc == 0) {
		/* normal program termination */
		child_groups_keepalive(&child_groups);
	} else {
		/* exception handler we got via setjump */
		/* restore signal handlers to default */
		signal(SIGTERM, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		child_groups_kill(&child_groups);
		exit(0);
	}
}
