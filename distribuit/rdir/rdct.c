/*
 * rdct.c

 * ReadDirClientTcp
 *  Created on: Jul 12, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */


#include "rd.h"

int main(int argc, char *argv[])
{
	char dir[DIRSIZE];
	int sd;
	struct sockaddr_in serv_addr;
	struct hostent *hp;
	if (argc != 3) {
		fprintf(stderr, "Usage: %s host_name dir_name\n", argv[0]);
		exit(-1);
	}
	/* open socket */
	if((sd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
		ERR("socket", 1);
	/* get server IP address */
	if(!(hp = gethostbyname(argv[1])))
		ERR("gethostbyname",2);
	/* prepare the address for connection */
	memset((char *)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy(hp -> h_addr, (char *) &serv_addr.sin_addr.s_addr, hp -> h_length);
	serv_addr.sin_port = htons(PORT_SERVER);

	/* create connection to the server */
	if (connect(sd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		ERR("connect", 3);
	/* request server for directory */
	if (send(sd, argv[2], strlen(argv[2]), 0 ) < 0)
		ERR("send", 4);
	/* wait for reply from server */
	if (recv(sd, dir, DIRSIZE, 0) < 0)
		ERR("recv", 5);
	/* print the result */
	printf("%s\n", dir);
	close(sd);
}
