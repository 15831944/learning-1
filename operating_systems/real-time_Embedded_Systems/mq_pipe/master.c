/*
 * master.c
 *
 *  Created on: Sep 19, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <spawn.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "mqheader.h"

extern int errno;

static void create_msg_queues(char *name, int msg_len) {
	struct mq_attr attr;
	mqd_t queue;
	mq_unlink(name);
	memset((void *)&attr, 0, sizeof(struct mq_attr));
	attr.mq_maxmsg = MQ_CAPACITY;
	attr.mq_msgsize = msg_len;
	if ((queue = mq_open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR, &attr)) == -1) {
		printf("Could not open queue: %s (%d)\n", strerror(errno), errno);
	}
	mq_close(queue);
}
int main(int argc, char **argv, char **env) {
	char *args0[] = {"mqwriter", "0", NULL};
	char *args1[] = {"mqwriter", "1", NULL};
	char *args2[] = {"mqreader", "2", NULL};

	posix_spawnattr_t inherit;

	pid_t pid, pidwa, pidwb, pidr;
	int status;

	create_msg_queues(MQ_NAME, sizeof(myMSG_t));

	pmsg[59] = '\n';
	memset(pmsg, ASCII_SPACE, PTR_STR_LEN - 1);
	memcpy(&pmsg[ptr_index[0]], "Writer A", 8);
	memcpy(&pmsg[ptr_index[1]], "Writer B", 8);
	memcpy(&pmsg[ptr_index[2]], "Reader", 6);
	memcpy(&pmsg[ptr_index[3]], "MQ status", 9);

	fprintf(stdout,"%s", pmsg);
	memset(pmsg, Hypen, PTR_STR_LEN - 1);
	fprintf(stdout, "%s", pmsg);

	inherit.__flags = 0;
	posix_spawn(&pidwa, args0[0], NULL, NULL, args0, env);
	posix_spawn(&pidwb, args1[0], NULL, NULL, args1, env);
	posix_spawn(&pidr, args2[0], NULL, NULL, args2, env);

	while(1) {
		if ((pid = wait(&status)) == -1) {
			perror("Master: ");
			mq_unlink(MQ_NAME);
			exit(EXIT_FAILURE);
		}
		printf("User process %d terminated\n", pid);
	}
}
