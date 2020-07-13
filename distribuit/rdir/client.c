/*
 * client.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT_SERVER 12345
#define IP_SERVER "127.0.0.1"
#define DIRSIZE 8192

int main(int argc, char *argv[])
{
	char dir[DIRSIZE];
	int sd;
	if (argc != 2) {
		printf("Ussage: %s directory\n", argv[0]);
		exit(-1);
	}
	struct sockaddr_in serv_addr;
	sd = socket(AF_INET, SOCK_STREAM, 0);
	memset((char *) &serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(IP_SERVER);
	serv_addr.sin_port = htons(PORT_SERVER);
	connect(sd,(struct sockaddr *) &serv_addr, sizeof(serv_addr));
	send(sd, argv[1], strlen(argv[1]), 0);
	recv(sd, dir, DIRSIZE, 0);
	printf("%s\n", dir);
	close(sd);
}
