/*
 * receiver.c
 * server part of socket UDP
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

char *host_name = "127.0.0.1";

void main() {
	int sin_len;
	int port = 6789;
	char message[256];
	int socket_descriptor;
	struct sockaddr_in sin;
	struct hostent *server_host_name;
	server_host_name = gethostbyname(host_name);
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(port);
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	bind(socket_descriptor, (struct sockaddr *)&sin, sizeof(sin));
	while(1) {
		sin_len = sizeof(sin);
		recvfrom(socket_descriptor, message, 256, 0, (struct sockaddr *)&sin,&sin_len);
		printf("\nResponse from server: \n %s\n", message);
		if (strncmp(message,"stop",4) == 0) break;
	}
	close(socket_descriptor);
}
