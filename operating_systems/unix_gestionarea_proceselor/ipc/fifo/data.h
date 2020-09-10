/*
 * data.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_FIFO_DATA_H_
#define IPC_FIFO_DATA_H_

typedef struct {
	long unused; //some info
	int pid; //process identificator
	int number; //message number
} Message;


#endif /* IPC_FIFO_DATA_H_ */
