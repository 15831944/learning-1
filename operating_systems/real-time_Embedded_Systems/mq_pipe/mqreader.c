/*
 * mqreader.c
 *
 *  Created on: Sep 19, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>

#include "mqheader.h"

int main(int argc, char **argv) {
	mqd_t myMQ;
	myMSG_t *MQ_msg_ptr;
	if (argc != 2) {
		fprintf(stderr,"Use: %s index", argv[0]);
		exit(EXIT_FAILURE);
	}
	int myindex = atoi(argv[1]);
	pmsg[PTR_STR_LEN - 1] = '\n';

	myMQ = mq_open(MQ_NAME, O_RDONLY);
	mqstat = (struct mq_attr *)malloc(sizeof(struct mq_attr));
	memset(mqstat, 0, sizeof(struct mq_attr));

	MQ_msg_ptr = (myMSG_t *)malloc(sizeof(myMSG_t));

	while(1) {
		sleep(2);
		if (MQ_size(myMQ) == 0)
			print_msg(myindex,".", empty_mq);
		sleep(1);
		memset(MQ_msg_ptr, 0, sizeof(myMSG_t));
		mq_receive(myMQ, MQ_msg_ptr, sizeof(myMSG_t), NULL);

		long size = MQ_size(myMQ);
		print_msg(myindex, MQ_msg_ptr -> content, mq_status(size));
	}
	mq_close(myMQ);
	return EXIT_SUCCESS;
}

