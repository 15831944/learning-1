/*
 * client_proc.h
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_SOCKETS_CLIENT_PROC_H_
#define IPC_SOCKETS_CLIENT_PROC_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

int connectTCP(char *h, char *s);
int connectUDP(char *h, char *s);
int connectsock(char *h, char *s, char *p);

#endif /* IPC_SOCKETS_CLIENT_PROC_H_ */
