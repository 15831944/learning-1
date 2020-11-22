/*
 * mqheader.h
 *
 *  Created on: Sep 19, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#ifndef MQ_PIPE_MQHEADER_H_
#define MQ_PIPE_MQHEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>

#define MQ_CAPACITY 5
#define PTR_STR_LEN 60
#define ASCII_SPACE 32
#define Hypen 45

typedef struct {
	int sequence;
	char content[10];
	char sender[10];
} myMSG_t;

char *senders[2] = {"Writer A", "Writer B"};
char *prefix [2] = {"(A,","(B."};
char MQ_NAME[] = "/mymq";
struct mq_attr *mqstat;
char pmsg[PTR_STR_LEN];
int ptr_index[] = {1, 15, 30, 45};
char empty_mq[] = "[.....]";
char full_mq[] = "[*****]";

void print_msg(int myindex, char *msg1, char *msg2) {
	memset(pmsg, ASCII_SPACE, PTR_STR_LEN-1);
	memcpy(&pmsg[ptr_index[myindex]], msg1, strlen(msg1));
	memcpy(&pmsg[ptr_index[3]], msg2, strlen(msg2));
	fprintf(stdout,"%s", pmsg);
	memset(pmsg, Hypen, PTR_STR_LEN -1);
	fprintf(stdout, "%s", pmsg);
}


long MQ_size(mqd_t _MQ) {
	if (mq_getattr(_MQ, mqstat) == -1)
		return -1;
	long nmsg = mqstat -> mq_curmsgs;
	return nmsg;
}

char *mq_status(long len) {
	char *status = (char *)malloc(MQ_CAPACITY + 3);
	memset(status, 0, MQ_CAPACITY + 3);
	strcpy(status,"[");
	long counter;
	for (counter = 1; counter <= len; counter++)
		strcat(status,"*");
	for (;counter < MQ_CAPACITY; counter ++)
		strcat(status, ".");
	strcat(status, "]");
	return status;
}
#endif /* MQ_PIPE_MQHEADER_H_ */
