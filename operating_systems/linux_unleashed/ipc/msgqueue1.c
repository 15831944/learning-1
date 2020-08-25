/*
 * msgqueue1.c
 * client for queue
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
	int status = msgrcv(id, (struct msgbuf *)&mq_test_buf, 80,123,IPC_NOWAIT);
	printf("received: %s with status %d\n", mq_test_buf.mtext, status);
	msgctl(id,IPC_RMID,0);
}
