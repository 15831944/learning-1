/*
 * whoc.c
 *
 *  Created on: Sep 11, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

void timeout(int);

int main(int argc, char **argv)
{
	int fd, i, rlen;
	char buf[1024], *host;
	struct sockaddr_in sin, raddr;
	struct sigaction sa;
	struct hostent *phe;
	struct servent *pse;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s host [options]\n", argv[0]);
		exit(1);
	}

	host = argv[1];
	bzero((char *)&sin,sizeof(sin));
	sin.sin_family = AF_INET;

	if ((pse = getservbyname("rwho", "udp")))
		sin.sin_port = pse -> s_port;
	else {
		fprintf(stderr, "Can't get rwho service entry\n");
		exit(1);
	}

	if ((phe = gethostbyname(host)) == NULL) {
		fprintf(stderr, "%s: %s cannot get local host\n", argv[0], host);
		exit(1);
	}
	bcopy(phe->h_addr, (char *)&sin.sin_addr, phe->h_length);

	if ((fd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		fprintf(stderr, "Error socket creation\n");
		exit(1);
	}
	strcpy(buf,"who");
	for(i = 2; i < argc; i++) {
		strcat(buf, " ");
		strcat(buf, argv[i]);
	}
	sa.sa_handler = timeout;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);
	alarm(20);
	if (sendto(fd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) < 0) {
		fprintf(stderr, "Error sendto\n");
		exit(1);
	}

	for(;;) {
		rlen = sizeof(raddr);
		if ((i = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&raddr, &rlen)) < 0) {
			fprintf(stderr, "Error recvfrom\n");
			exit(1);
		}
		if ((i == 1) && (buf[0] == '\0'))
			exit(0);
		write(1, buf, i);
	}
}

void timeout(int s)
{
	fprintf(stderr,"rwho: command timed out!\n");
	exit(1);
}
