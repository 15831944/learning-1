/*
 * child.c
 *
 *  Created on: Aug 9, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#ifndef _CHILD_H
#define _CHILD_H

#ifdef __cplusplus
extern "C" {
#endif
#define MAX_CHILDREN 32
#define MAX_CHILD_GROUPS 4

extern int child_debug;
/* we have circular reference here */
struct child_info_t;

typedef void (*child_fp_t)(struct child_info_t *, void *);
typedef struct child_info_t {
	int pid;
	int ppid;
	int number;
	child_fp_t child_fp;
} child_info_t;

/* the following shoudl really be kept in shared memory */
typedef struct {
	int nchildren; /* number in table, not number running */
	int minchildren;
	int maxchildren;
	int activechildren;
	child_info_t child[MAX_CHILDREN];
} child_group_info_t;

typedef struct {
	int ngroups;
	child_group_info_t *group[MAX_CHILD_GROUPS];
} child_groups_t;

void child_create(child_info_t * child_info_p, child_fp_t child_fp, void *private_p);

child_info_t *child_lookup_by_pid(const child_groups_t *child_groups_p, int pid);

int child_group_create(child_group_info_t *children_info_p, const int min, const int max, const child_fp_t child_fp, void *private_p);

extern int child_restart_children;
extern void child_groups_keepalive(const child_groups_t *child_groups_p);
extern int child_group_signal(child_group_info_t *children_info_p, int signal);
extern int child_groups_signal(const child_groups_t *child_groups_p, int signal);
extern int child_groups_kill(const child_groups_t *child_groups_p);

extern int child_pipeve(
		const char *cmdpath, /* full path to command */
		char *const argv[], /* array of pointers to arguments */
		char * const env[], /* array of pointers to environment vars */
		int *stdin_fd_p, /* output: fd for stdin pipe */
		int *stdout_fd_p, /* output: fd for stdout pipe */
		int *stderr_fd_p /* output: fd for stderr pipe */
);

extern void child_print_arg_array(char *name, char * const array[]);
extern void child_init();
extern void child__term();

#ifdef __cplusplus
}
#endif

#endif
