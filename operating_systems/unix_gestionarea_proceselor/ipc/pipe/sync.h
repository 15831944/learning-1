/*
 * sync.h
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef SIGNALS_SYNC_H_
#define SIGNALS_SYNC_H_

#include <sys/types.h>
#include <unistd.h>
#include "../../common/hdr.h"

void config(void);

void Tell_P(pid_t pid);
void Wait_P(void);
void Tell_F(pid_t pid);
void Wait_F(void);

#endif /* SIGNALS_SYNC_H_ */
