/*
 * inet.h
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 24, 2021
 *      Author: Gabriel Dimitriu
 */

#ifndef DIN_REVISTE_INET_H_
#define DIN_REVISTE_INET_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/syslog.h>
#include <unistd.h>
#include <stdlib.h>

#define SERV_UDP_PORT 6543
#define SERV_TCP_PORT 6543
#define SERV_HOST_ADDR "127.0.0.1"

extern char *pname;

#define MAXLINIE 512
#define MAXMESAJ 2048

int writen(int,char *,int);
int citestelinie(int,char *, int);

#endif /* DIN_REVISTE_INET_H_ */
