/*
 * rdst.c
 * ReadDirServerTcp
 *  Created on: Jul 12, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "rd.h"
#include "read_dir.c"

int main()
{
	char dir[DIRSIZE];
	int sd, fd, len_addr;
	struct sockaddr_in serv_addr, client_addr;

	signal(SIGCHLD, SIG_IGN); // to avoid zombie

	/* create a socket */
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR("socket", 1);
	/* prepare the server address */
	memset((char *) &serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT_SERVER);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	/* bind server address */
	if(bind(sd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0)
		ERR("bind", 2);
	/* listen */
	if (listen(sd, 5) != 0)
		ERR("listen", 3);

	/* main infinite loop */
	for(;;) {
		/* accept client connection */
		if((fd = accept(sd, (struct sockaddr *) &client_addr, &len_addr)) < 0)
			ERR("accept", 4);
		/* receive request from client */
		if(recv(fd, dir, DIRSIZE, 0) < 0)
			ERR("recv", 5);
		/* separate process for client request */
		if(fork() == 0) {
			close(sd);
			read_dir(dir);
			/* send answer to client */
			if(send(fd, dir, strlen(dir), 0) < 0)
				ERR("send", 6);
			close(fd);
			exit(0);
		}
	}
}
