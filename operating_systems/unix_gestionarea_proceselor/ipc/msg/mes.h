/*
 * mes.h
 *
 *  Created on: Sep 9, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_MSG_MES_H_
#define IPC_MSG_MES_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 13

#define READ 1
#define WRITE 2

typedef struct {
	long mtip;
	int pid;
	int cod_op;
	char mtext[13];
} Message;

#endif /* IPC_MSG_MES_H_ */
