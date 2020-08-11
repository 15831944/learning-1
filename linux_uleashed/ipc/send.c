/*
 * send.c
 * example of UDP client
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

int port = 6789;

void main() {
	int socket_descriptor;
	int iter = 0;
	int process;
	char buf[80];
	struct sockaddr_in address;
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(port);
	process = 1;
	do {
		sprintf(buf, "data packet with ID %d\n", iter);
		if (iter > 20) {
			sprintf(buf, "stop\n");
			process = 0;
		}
		sendto(socket_descriptor, buf, sizeof(buf), 0, (struct sockaddr *)&address, sizeof(address));
		iter++;
	}while (process);
	close(socket_descriptor);
}
