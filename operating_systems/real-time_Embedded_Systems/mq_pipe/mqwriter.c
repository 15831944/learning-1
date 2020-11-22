/*
 * mqwriter.c
 *
 *  Created on: Sep 19, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdlib.h>
#include <stdio.h>
#include <mqueue.h>

#include "mqheader.h"

/*
=============
itoa

Convert integer to string

PARAMS:
- value     A 64-bit number to convert
- str       Destination buffer; should be 66 characters long for radix2, 24 - radix8, 22 - radix10, 18 - radix16.
- radix     Radix must be in range -36 .. 36. Negative values used for signed numbers.
=============
*/

char* itoa (unsigned long long  value,  char str[],  int radix)
{
    char        buf [66];
    char*       dest = buf + sizeof(buf);
    int     sign = 0;

    if (value == 0) {
        memcpy (str, "0", 2);
        return str;
    }

    if (radix < 0) {
        radix = -radix;
        if ( (long long) value < 0) {
            value = -value;
            sign = 1;
        }
    }

    *--dest = '\0';

    switch (radix)
    {
    case 16:
        while (value) {
            * --dest = '0' + (value & 0xF);
            if (*dest > '9') *dest += 'A' - '9' - 1;
            value >>= 4;
        }
        break;
    case 10:
        while (value) {
            *--dest = '0' + (value % 10);
            value /= 10;
        }
        break;

    case 8:
        while (value) {
            *--dest = '0' + (value & 7);
            value >>= 3;
        }
        break;

    case 2:
        while (value) {
            *--dest = '0' + (value & 1);
            value >>= 1;
        }
        break;

    default:            // The slow version, but universal
        while (value) {
            *--dest = '0' + (value % radix);
            if (*dest > '9') *dest += 'A' - '9' - 1;
            value /= radix;
        }
        break;
    }

    if (sign) *--dest = '-';

    memcpy (str, dest, buf +sizeof(buf) - dest);
    return str;
}

void send_msg(char *sender, int sequence, char *msg, mqd_t _MQ) {
	myMSG_t *_msg = (myMSG_t *)malloc(sizeof(myMSG_t));
	memset(_msg, 0, sizeof(myMSG_t));
	_msg -> sequence = sequence;
	memcpy(_msg->content, msg, strlen(msg));
	memcpy(_msg->sender, sender, strlen(sender));
	mq_send(_MQ, _msg, sizeof(myMSG_t), 0);
	free(_msg);
}

int main(int argc, char **argv) {
	mqd_t myMQ;
	static int seq = 0;
	if (argc != 2) {
		fprintf(stderr,"Use: %s index\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int myindex = atoi(argv[1]);
	char *sender = senders[myindex];
	pmsg[PTR_STR_LEN - 1] = '\n';
	myMQ = mq_open(MQ_NAME, O_WRONLY);
	mqstat = (struct mq_attr *)malloc(sizeof(struct mq_attr));
	memset(mqstat, 0, sizeof(struct mq_attr));

	while(1) {
		int r = rand() %3 +1;
		sleep(r);
		char *msg = (char *)malloc(10);
		memset(msg, 0, 10);
		strcpy(msg, prefix[myindex]);
		itoa(++seq, msg+strlen(msg), 10);
		strcat(msg, ")");
		if (MQ_size(myMQ) == MQ_CAPACITY)
			print_msg(myindex, ".", full_mq);
		send_msg(sender, seq, msg, myMQ);
		long size = MQ_size(myMQ);
		print_msg(myindex, msg, mq_status(size));
	}
	mq_close(myMQ);
	return EXIT_SUCCESS;
}
