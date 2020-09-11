/*
 * socket_pasiv.c
 *
 *  Created on: Sep 11, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "socket_pasiv.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int errno;
extern const char * const sys_errlist[];
u_short portabse = 100;

int passiveTCP(char *service, int qlen)
{
	return (passivesock(service, "tcp",qlen));
}

int passiveUDP(char *service, int qlen)
{
	return (passivesock(service, "udp", qlen));
}

int passivesock(char *s, char *p, int qlen)
{
	struct servent *pse;
	struct protoent *ppe;
	struct sockaddr_in sin;

	int type, sock;

	bzero((char *)&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;

	if ((pse = getservbyname(s, p)))
		sin.sin_port = htons(htons((u_short)pse -> s_port) + portabse);
	else if ((sin.sin_port = htons((u_short) atoi(s))) == 0) {
		printf("Can't get %s service entry\n", s);
		exit(1);
	}
	if ((ppe = getprotobyname(p)) == 0) {
		printf("Can't get %s protocol entry\n", p);
		exit(1);
	}
	if (strcmp(p, "upd") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;
	if ((sock = socket(PF_INET, type, ppe->p_proto)) < 0) {
		printf("Can't create socket %s\n", sys_errlist[errno]);
		exit(1);
	}
	if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		printf("Con't bind to %s port: %s\n", s, sys_errlist[errno]);
		exit(1);
	}
	if (type == SOCK_STREAM && listen(sock, qlen) < 0) {
		printf("Can't listen on %s port: %s\n", s, sys_errlist[errno]);
		exit(1);
	}
	return (sock);
}
