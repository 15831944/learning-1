/*
 * execs.h
 *
 *  Created on: Aug 31, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#ifndef EXEC_EXECS_H_
#define EXEC_EXECS_H_

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int execs(const char *cmdline);

#endif /* EXEC_EXECS_H_ */
