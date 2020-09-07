/*
 * sig.h
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef SIGNALS_SIG_H_
#define SIGNALS_SIG_H_

#include <signal.h>
#include "../common/hdr.h"

sigfunc *signal(int sig, sigfunc *func);

#endif /* SIGNALS_SIG_H_ */
