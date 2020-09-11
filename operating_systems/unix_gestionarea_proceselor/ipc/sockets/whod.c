/*
 * whod.c
 * dont' forget to put into /etc/services rwho port/udp
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

int main(int argc, char **argv)
{
	FILE *fp;
	int fd, i, rlen;
	char buf[1024], raddr[128], *host;
	struct sockaddr_in sin;
	struct hostent *phe;
	struct servent *pse;
	struct sigaction sa;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s host\n", argv[0]);
		exit(1);
	}
	host = argv[1];

	bzero((char *)&sin, sizeof(sin));
	sin.sin_family = AF_INET;

	if ((pse = getservbyname("rwho", "udp")))
		sin.sin_port = pse -> s_port;
	else {
		fprintf(stderr, "Can't get rwho service entry\n");
		exit(1);
	}
	if ((phe = gethostbyname(host)) == NULL) {
		fprintf(stderr, "%s: %s cannot get server host\n", argv[0], host);
		exit(1);
	}

	bcopy(phe->h_addr, (char *)&sin.sin_addr, phe->h_length);

	if ((fd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		fprintf(stderr, "Cannot create socket !\n");
		exit(1);
	}
	if (bind(fd,(struct sockaddr *)&sin, sizeof(struct sockaddr_in)) < 0) {
		fprintf(stderr,"Cannot bind\n");
		exit(1);
	}
	for(;;) {
		rlen = sizeof(raddr);
		if ((i = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)raddr, &rlen)) < 0) {
			fprintf(stderr, "Error: recvfrom\n");
			exit(1);
		}
		fp = popen(buf,"r");
		if (fp) {
			while(fgets(buf, sizeof(buf), fp)) {
				if (sendto(fd, buf, strlen(buf) + 1, 0, (struct sockaddr *)raddr, rlen) < 0) {
					fprintf(stderr, "Error: sento\n");
					exit(1);
				}
			}
			pclose(fp);
			buf[0] = '\0';
			if (sendto(fd, buf, 1, 0, (struct sockaddr *)raddr, rlen) < 0) {
				fprintf(stderr, "Error sendto\n");
				exit(1);
			}
		}
		else {
			fprintf(stderr,"Cannot exec command\n");
			exit(1);
		}
	}
}
