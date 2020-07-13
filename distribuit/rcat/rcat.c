/*
 * rcat.c
 * TFTP client
 *  Created on: Jul 13, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include <sys/types.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern int errno;
#define ERR(S,N) {fprintf(stderr,"\n%d\n Usage: rcat MachineName File \n", N);\
	perror(S); exit(N); }
#define PORT_TFTP 69 //TFTP access port
#define BSIZE 600 //size of the data buffer
#define MODE "octet"

#define OP_RRQ 1
#define OP_DATA 3
#define OP_ACK 4
#define OP_ERROR 5

int main(int argc, char *argv[])
{
	int sock; //socket descriptor
	struct sockaddr_in server; // server address
	struct sockaddr_in client; // client address
	struct hostent *host; // info from server host
	char buffer[BSIZE], *p;
	int len_addr, contor;
	if(argc != 3)
		ERR("arguments", 1);
	/* create a dgram socket */
	sock = socket (AF_INET, SOCK_DGRAM, 0);
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = htonl(INADDR_ANY);
	client.sin_port = 0; //the system will choose the port
	/* bind the client */
	if (bind(sock, (struct sockaddr *) &client, sizeof(client)) < 0)
		ERR("bind", 2);
	/* get the server address */
	host = gethostbyname(argv[1]);
	if (host == NULL)
		ERR(argv[1],3);
	server.sin_family = AF_INET;
	memcpy(&server.sin_addr.s_addr, host -> h_addr, host -> h_length);
	server.sin_port = htons(PORT_TFTP);
	/* create TFTP READ REQUEST package */
	*(short *)buffer = htons(OP_RRQ); // operation code in the network order
	p = buffer + 2;
	strcpy(p, argv[2]); // name of the file
	p += strlen(argv[2]) + 1; // keep \0
	strcpy(p, MODE); // the mode
	p += strlen(MODE) + 1; //keep \0
	/* send READ REQUEST to TFTP server, length is compute from pointer difference */
	if (sendto(sock, buffer, p - buffer, 0, (struct sockaddr *)&server, sizeof(server)) < 0)
		ERR("sendto RRQ", 4);
	/* collect the data packages from server until a short package will arrive*/
	do {
		len_addr = sizeof(server);
		if ((contor = recvfrom(sock, buffer, BSIZE, 0, (struct sockaddr *) &server, &len_addr)) < 0)
			ERR("recvfrom", 5);
		if (htons (*(short *)buffer) == OP_ERROR) {
			ERR("recvfrom OP_ERROR", 5);
		}
		else {
			/* we have found a good block */
			write(1, buffer + 4, contor -4);
			/* send ack the package  block is already into the buffer so we have just to put
			 * operation code and send first 4 octets. The ACK is send to the port received from
			 * server and not 69
			 */
			*(short *) buffer = htons (OP_ACK);
			if (sendto(sock, buffer, 4, 0, (struct sockaddr *)&server, sizeof(server)) < 0)
				ERR("sento ACK",7);
		}
	} while (contor == 516);
}
