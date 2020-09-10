/*
 * mesaje.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_FIFO_MESSAGE_H_
#define IPC_FIFO_MESSAGE_H_
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define MAXOPEN 7 	// maximum number of open FIFO files
#define MAXTRIES 3 	//maximum number of tries to open
#define NAPTIME	5	//delay between tries
#define MAXMSG 7
#define FALSE 0
#define TRUE 1

int sendQueue(int dstkey, char *buf, int nbytes);
int receiveQueue(int srckey, char *buf, int nbytes);
void rmqueue(int key);

#endif /* IPC_FIFO_MESSAGE_H_ */
