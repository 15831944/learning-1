/*
 * message.h
 *
 *  Created on: Sep 9, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_MSG_MESSAGE_H_
#define IPC_MSG_MESSAGE_H_

#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include "../../common/hdr.h"

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[1];    /* message data */
};

#define MAXOPEN 20 //number of open queues
#define MAXMSG 4 //max number of messages
typedef enum { FALSE, TRUE} BOOLEAN;

BOOLEAN sendQueue(int dstkey, struct msgbuf *buf, int nbytes);
BOOLEAN receiveQueue(int srckey, struct msgbuf *buf, int nbytes);
void rmqueue(int key);
#endif /* IPC_MSG_MESSAGE_H_ */
