/*
 * server.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT_SERVER 12345
#define DIRSIZE 8192
#include "read_dir.c"

int main()
{
	char dir[DIRSIZE];
	int sd, fd, len_addr;
	struct sockaddr_in serv_addr, client_addr;

	signal (SIGCHLD, SIG_IGN); //evitare zombie

	sd = socket(AF_INET, SOCK_STREAM, 0);
	memset((char *)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT_SERVER);
	bind(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	listen(sd, 5);
	for(;;) { // bucla principala
		fd = accept(sd, (struct sockaddr *)&client_addr, &len_addr);
		recv(fd, dir, DIRSIZE, 0);
		if (fork() == 0) {
			close(sd);
			read_dir(dir);
			send(fd, dir, strlen(dir), 0);
			close(fd);
			exit(0);
		}
	}
}
