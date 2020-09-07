/*
 * hdr.h
 *
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef COMMON_HDR_H_
#define COMMON_HDR_H_

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 1024
#define ever (;;)

typedef void sigfunc(int);
void print_exit(int);
void print_mask(const char *);
sigfunc *signal_intr(int, sigfunc *);
void err_sys(const char *,...);
void err_quit(const char *,...);
void err_dump(const char *,...);
void err_ret(const char *,...);
void err_msg(const char *,...);
#endif /* COMMON_HDR_H_ */
