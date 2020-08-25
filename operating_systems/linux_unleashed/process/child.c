/*
 * child.c
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
#include <errno.h>
#include "child.h"

/* Linux doesn't even bother to declare DST_NONE */
#ifndef DST_NONE
	#define DST_NONE 0
#endif

int child_debug = 0;
void child_create(child_info_t *child_info_p, child_fp_t child_fp, void *private_p) {
	int rc;
	int fd;
	int seed;
	struct timeval tv;
	struct timezone tz;
	assert(child_info_p);
	assert(child_fp);

	/* struct timezone is obsolete and not really used under Linux */
	tz.tz_minuteswest = 0;
	tz.tz_dsttime = DST_NONE;
	rc = fork();
	if (rc == (pid_t) -1) {
		/* errror */
		perror("fork failed");
	} else if (rc > 0) {
		/* parent */
		child_info_p -> pid = rc;
	} else {
#ifndef USING_SHARED_MEM
		child_info_p -> pid = getpid();
		child_info_p -> ppid = getppid();
#endif
		/* resed random number generator*/
		/* if you don't do this in each child they are likely to all use the same random number stream */
		fd = open("/dev/random", O_RDONLY);
		assert(fd >= 0);
		rc = read(fd, &seed, sizeof(seed));
		assert(rc == sizeof(seed));
		close(fd);
		srandom(seed);

		gettimeofday(&tv, NULL);
		fprintf(stderr,"%0010d.%06d: Starting child process #%d, pid = %d, parent = %d\n", tv.tv_sec, tv.tv_usec, child_info_p -> number, child_info_p -> pid, child_info_p -> ppid);
		child_info_p -> child_fp = child_fp;
		child_fp(child_info_p, private_p);

		gettimeofday(&tv, NULL);
		fprintf(stderr,"%0010d.%06d: Finised child process #%d, pid = %d, parent = %d\n", tv.tv_sec, tv.tv_usec, child_info_p -> number, child_info_p -> pid, child_info_p -> ppid);
		/* child process ceses to exist here */
		exit(0);
	}
}

child_info_t *child_lookup_by_pid(const child_groups_t *child_groups_p, int pid) {
	int i;
	int j;
	assert(child_groups_p);
	for(i = 0; i < child_groups_p -> ngroups; i++) {
		for(j = 0; j < child_groups_p -> group[i] -> nchildren; j++) {
			if (child_groups_p -> group[i] -> child[j].pid == pid) {
				return &child_groups_p -> group[i] -> child[j];
			}
		}
	}
	return NULL;
}

int child_group_create(child_group_info_t *children_info_p, const int min, const int max, const child_fp_t child_fp, void *private_p) {
	int i;
	children_info_p -> nchildren = min;
	children_info_p -> maxchildren = max;
	children_info_p -> minchildren = min;

	for(i = 0; i < min; i++) {
		children_info_p -> child[i].number = i;
		children_info_p -> child[i].child_fp = child_fp;
		child_create(&children_info_p -> child[i], child_fp, private_p);
	}

	children_info_p -> activechildren = min;

	return 0;
}

int child_restart_children = 1;
/*
 * this function currently does not change the number of children
 * In the fufure it could be extended to change the number of children
 * based on load.
 * Each time a child exited, it could restart 0, 1 or 2 children instead of 1.
 */
void child_groups_keepalive(const child_groups_t *child_groups_p) {
	int rc;
	int child_status;
	int pid;
	child_info_t *child_p;
	while(1) {
		rc = wait(&child_status);
		if (child_restart_children == 0) {
			fprintf(stderr,"child_groups_keepaline(): exiting\n");
			return;
		}
		if (rc > 0) {
			fprintf(stderr,"wait(): returned %d\n", rc);
			pid = rc;
			if (WIFEXITED(child_status)) {
				fprintf(stderr, "child exited normally\n");
			}
			if (WIFSIGNALED(child_status)) {
				fprintf(stderr,"child exited due to signal %d\n", WTERMSIG(child_status));
			}
			if (WIFSTOPPED(child_status)) {
				fprintf(stderr,"child suspend due to signal %d\n", WSTOPSIG(child_status));
			}
			/*
			 * use kill with 0 to see if child still exists
			 * we could also use results of WIFEXITED() and WIFSIGNALED
			 */
			if (kill(pid,0)) {
				child_p = child_lookup_by_pid(child_groups_p, pid);
				assert(child_p);
				fprintf(stderr, "child %d, pid = %d, died restarting\n", child_p -> pid, pid);
				child_create(child_p, child_p -> child_fp, NULL);
			} else {
				fprintf(stderr,"Child pid %d still exists\n", pid);
			}
		}
	}
}

int child_group_signal(child_group_info_t *children_info_p, int signal) {
	int i;
	int count;
	int rc;
	child_info_t *child_p;

	assert(children_info_p);
	assert(signal >= 0);
	count = 0;
	for(i = 0; i < children_info_p -> nchildren;  i++) {
		child_p = &children_info_p -> child[i];
		fprintf(stderr,"sending signal %d to pid %d\n", signal, child_p -> pid);
		rc = kill(child_p -> pid, signal);
		if (rc == 0)
			count++;
	}
	return count;
}

int child_groups_signal(const child_groups_t *child_groups_p, int signal) {
	int i;
	int pid;
	int count;

	assert(child_groups_p);
	assert(signal >= 0);
	count =0;
	for(i = 0; i < child_groups_p -> ngroups; i++) {
		count += child_group_signal(child_groups_p -> group[i], signal);
	}
	return count;
}

int child_groups_kill(const child_groups_t *child_groups_p) {
	int child_count;
	int rc;
	int i;

	assert(child_groups_p);
	child_count = child_groups_signal(child_groups_p, 0);
	fprintf(stderr, "total children = %d\n", child_count);

	fprintf(stderr,"sending SIGTERM\n");
	child_groups_signal(child_groups_p, SIGTERM);
	/* wait up to 4 minutes for childre to die*/
	/* wait() may hang if children are already gone */
	for (i = 0; i < 24; i++) {
		rc = child_groups_signal(child_groups_p, 0);
		if (rc == child_count)
			return child_count;
		sleep(5);
	}
	fprintf(stderr, "some children did not die\n");
	fprintf(stderr, "sending SIGKILL\n");
	return child_groups_signal(child_groups_p, SIGKILL) + rc;
}

/* debugging function for argv and envp */
void child_print_arg_array(char *name, char *const array[]) {
	int i;
	i = 0;
	while(1) {
		if (array[i]) {
			fprintf(stderr,"%s[%d]=\"%s\"\n", name,i, array[i]);
		} else {
			fprintf(stderr,"%s[%d]=NULL\n", name,i);
			break;
		}
		i++;
	}
}

extern char **environ;
/*
 * this function is intended as a replacement for system() and popn() which is
 * more secure and flexible.
 * argv and envp must este with a NULL pointer, stdin_fp_p, stdout_fp_p may be NULL
 * in  which case that steam will not be piped
 * you may want to use fd_open() on the pipes to use stdio
 * argv[0] should equal cmdpath
 */
int child_pipeve(
		const char *cmdpath, /* full path to command */
		char * const argv[], /* array of pointers to arguments */
		char * const envp[], /* array of pointers to env. vars */
		int *stdin_fd_p, /* output: fd for stdin pipe */
		int *stdout_fd_p, /* output: fd for stdout pipe */
		int *stderr_fd_p /*output: fd for stderr pipe */
) {
	int rc;
	int pid;
	int status;
	int stdin_pipe[2];
	int stdout_pipe[2];
	int stderr_pipe[2];
	char *dummy_argv[8];
	char *dummy_envp[8];

	stdin_pipe[0] = -1;
	stdin_pipe[1] = -1;
	stdout_pipe[0] = -1;
	stdout_pipe[1] = -1;
	stderr_pipe[0] = -1;
	stderr_pipe[1] = -1;

	if (stdin_fd_p) {
		rc = pipe(stdin_pipe);
		if(rc != 0) return -1;
		*stdin_fd_p = stdin_pipe[1];
	}

	if (stdout_fd_p) {
		rc = pipe(stdout_pipe);
		if (rc != 0) {
			if (stdin_pipe[0] >= 0) close(stdin_pipe[0]);
			if (stdin_pipe[1] >= 0) close(stdin_pipe[1]);
			return -1;
		}
		*stdout_fd_p = stdout_pipe[1];
	}

	if (stderr_fd_p && (stderr_fd_p != stdout_fd_p)) {
		rc = pipe(stderr_pipe);
		if (rc != 0) {
			if (stdin_pipe[0] >= 0) close(stdin_pipe[0]);
			if (stdin_pipe[1] >= 0) close(stdin_pipe[1]);
			if (stdout_pipe[0] >= 0) close(stdout_pipe[0]);
			if (stdout_pipe[1] >= 0) close(stdout_pipe[1]);
			return -1;
		}
		*stderr_fd_p = stderr_pipe[1];
	}

	rc = fork();
	if (rc < 0) {
		/* error */
		return -1;
	} else if(rc == 0) {
		/* child */
		if (stdin_fd_p) {
			/* redirect stdin */
			rc = dup2(stdin_pipe[0], 0);
		}
		if (stdout_fd_p) {
			/* rediret stdout */
			rc = dup2(stdout_pipe[1], 1);
		}
		if (stderr_fd_p) {
			/* redirect stderr */
			if (stderr_fd_p == stdout_fd_p) {
				rc = dup2(stdout_pipe[1],2);
			} else {
				rc = dup2(stderr_pipe[1], 2);
			}
		}
		/* clean up file descriptors */
#if 0
		for (i = 3 ; i < OPEN_MAX; i++) {
			close(i);
		}
#endif
		if (envp == NULL) envp = environ;
		if (child_debug >= 5) {
			child_print_arg_array("argv",argv);
			child_print_arg_array("envp", envp);
			fprintf(stderr,"cmdpath=\"%s\"\n", cmdpath);
		}
		fprintf(stderr,"about to execve()\n");
#if 1
		execve(cmdpath, argv, envp);
#else
		dummy_argv[0] = "./child_demo4";
		dummy_argv[1] = "one";
		dummy_argv[2] = "two";
		dummy_argv[3] = "three";
		dummy_argv[4] = NULL;
		dummy_envp[0] = "PATH=/bin:/usr/bin";
		dummy_envp[1] = NULL;
		execve("./child_demo4", dummy_argv,dummy_envp);
#endif
		fprintf(stderr,"execve() failed");
		perror("execve() ");
		exit(255);
	} else {
		/* parent */
		pid = rc;
#if 0
		rc = wait4(pid,&status,0,NULL);
#else
		rc = waitpid(pid, &status, 0);
#endif
		if (rc <0) {
			/* wait4() set errno */
			return -1;
		}
		if (WIFEXITED(status)) {
			fprintf(stderr,"child_pipve(): child exited normally\n");
			return (int)(signed char)WEXITSTATUS(status);
		} else if (WIFSIGNALED(status)) {
			fprintf(stderr,"cild_pipve(): child cought signal\n");
			errno = EINTR;
			return -1;
		} else {
			fprintf(stderr,"child_pipve(): unknown child status \n");
			errno = EINTR;
			return -1;
		}
	}
}

void child_init()
{

}

void child_term()
{

}
