/*
 * msgqueue2.c
 * server for queue
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct amsgbuf {
	long mtype;
	char mtext[80];
};
int main() {
	key_t unique_key = 123456;
	int id = msgget(unique_key, IPC_CREAT | 0666);
	printf("id of queue = %d\n",id);
	struct amsgbuf mq_test_buf;
	mq_test_buf.mtype = 123;
	sprintf(mq_test_buf.mtext, "test message");
	int status = msgsnd(id, (struct msgbuf *)&mq_test_buf, strlen(mq_test_buf.mtext) + 1, 0);
	printf("Send with status %d\n", status);
	fflush(stdout);
}
