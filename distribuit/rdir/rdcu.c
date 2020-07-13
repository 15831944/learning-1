/*
 * rdcu.c
 * Read Dir Client on UDP
 *  Created on: Jul 13, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */


#include "rd.h"

int main(int argc, char *argv[])
{
	char dir[DIRSIZE];
	int sd, len_addr;
	struct sockaddr_in serv_addr, client_addr;
	struct hostent *hp;
	if (argc != 3) {
		fprintf(stderr,"Usage: %s server_host dir_request\n", argv[0]);
		exit(-1);
	}
	/* open a socket */
	if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		ERR("socket",1);
	/* get the IP address of the server */
	if (!(hp = gethostbyname(argv[1])))
		ERR("gethostbyname",2);
	/* prepare the address for connection */
	memset((char *)&serv_addr, 0 , sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy(hp -> h_addr, (char *)&serv_addr.sin_addr.s_addr, hp -> h_length);
	serv_addr.sin_port = htons(PORT_SERVER);

	/* prepare adddress for bind */
	memset((char *)&client_addr, 0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	client_addr.sin_port = htons(0);
	/* bind */
	if (bind(sd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
		ERR("bind", 3);
	/* send request to the server */
	if (sendto(sd, argv[2], strlen(argv[2]), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		ERR("sendto", 4);
	/* wait for reply from server */
	len_addr = sizeof(serv_addr);
	memset((char *)&serv_addr, 0, len_addr);
	if (recvfrom(sd, dir, DIRSIZE, 0, (struct sockaddr *)&serv_addr, &len_addr) < 0)
		ERR("recvfrom", 5);
	/* print the result */
	printf("%s\n", dir);
	close(sd);
}
