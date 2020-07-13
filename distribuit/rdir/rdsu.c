/*
 * rdsu.c
 * Read Dir Server on UDP
 *  Created on: Jul 13, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "rd.h"
#include "read_dir.c"

int main()
{
	char dir[DIRSIZE];
	int sd, len_addr;
	struct sockaddr_in serv_addr, client_addr;
	/* signal to prevent zombie */
	signal (SIGCHLD, SIG_IGN);
	/* create socket */
	if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		ERR("socket", 1);
	/* prepare server address */
	memset((char *)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT_SERVER);
	/* bind */
	if (bind(sd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		ERR("bind", 2);
	/* main loop server */
	for(;;) {
		memset((char *)&client_addr, 0, sizeof(client_addr));
		len_addr = sizeof(client_addr);
		/* wait for a client request */
		if(recvfrom(sd, dir, DIRSIZE, 0, (struct sockaddr *)&client_addr, &len_addr) < 0)
			ERR("recvfrom", 3);
		/* serve the client into a separate process */
		if(fork() == 0) {
			read_dir(dir);
			/* send the request */
			if(sendto(sd, dir, strlen(dir), 0, (struct sockaddr *)&client_addr, len_addr) < 0)
				ERR("sendto", 4);
			close(sd);
			exit(0);
		}
	}
}
