/*
 * rd.h
 *
 *  Created on: Jul 12, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#ifndef RDIR_RD_H_
#define RDIR_RD_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

// indicatorul de erori ale apelurilor system
extern int errno;

#define ERR(S,N) {fprintf(stderr,"\n%d ", N); \
	perror(S); exit(N);}

#define PORT_SERVER 12347
#define DIRSIZE 8192


#endif /* RDIR_RD_H_ */
