/*
 * pv.h
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_SEM_PV_H_
#define IPC_SEM_PV_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "../../common/hdr.h"

void P(int semid);
void V(int semid);

#endif /* IPC_SEM_PV_H_ */
