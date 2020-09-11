/*
 * client_proc.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client_proc.h"

extern int errno;
extern const char * const sys_errlist[];

int connectTCP(char *h, char *s)
{
	return connectsock(h,s, "tcp");
}

int connectUDP(char *h, char *s)
{
	return connectsock(h,s, "udp");
}

int connectsock(char *h, char *s, char *p)
{
	struct servent *pse; //pointer to service entry
	struct hostent *phe; //pointer to host entry
	struct protoent *ppe; //pointer to protocol entry
	struct sockaddr_in sin; //address IP

	int type, sock;

	bzero((char *)&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	if ((pse = getservbyname(s, p)))
		sin.sin_port = pse->s_port;
	else if ((sin.sin_port = htons((u_short)atoi(s))) == 0) {
		printf("Could not get %s service entry\n", s);
		exit(1);
	}
	if ((phe = gethostbyname(h)))
		bcopy(phe->h_addr, (char *)&sin.sin_addr, phe->h_length);
	else if ((sin.sin_addr.s_addr = inet_addr(h)) == INADDR_NONE) {
		printf("Could not get %s host entry\n", h);
		exit(1);
	}
	if ((ppe = getprotobyname(p)) == 0) {
		printf("Could not get %s protocol entry\n", p);
		exit(1);
	}

	if (strcmp(p, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

	if ((sock = socket(PF_INET, type, ppe->p_proto)) < 0) {
		printf("Could not create socket %s\n", sys_errlist[errno]);
		exit(1);
	}

	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		printf("Could not connect to %s.%s: %s\n", h, s, sys_errlist[errno]);
		exit(1);
	}
	return sock;
}

