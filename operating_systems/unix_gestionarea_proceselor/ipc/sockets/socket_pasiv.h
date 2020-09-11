/*
 * socket_pasiv.h
 *
 *  Created on: Sep 11, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_SOCKETS_SOCKET_PASIV_H_
#define IPC_SOCKETS_SOCKET_PASIV_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

int passiveTCP(char *service, int qlen);
int passiveUDP(char *service, int qlen);
int passivesock(char *s, char *p, int qlen);

#endif /* IPC_SOCKETS_SOCKET_PASIV_H_ */
