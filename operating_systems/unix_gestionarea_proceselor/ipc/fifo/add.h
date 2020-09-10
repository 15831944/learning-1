/*
 * add.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_FIFO_ADD_H_
#define IPC_FIFO_ADD_H_

#define SERVERKEY 13

typedef struct {
	long unused;
	long clientkey;
	int x;
	int y;
	int sum;
} Message;

#endif /* IPC_FIFO_ADD_H_ */
