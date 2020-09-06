/*
 * interfata.h
 *
 *  Created on: Sep 6, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_FILE_INTERFATA_H_
#define IPC_FILE_INTERFATA_H_

typedef struct {
	char command[128];
	float fvalue;
	int ivalue;
} INTERF;

#endif /* IPC_FILE_INTERFATA_H_ */
