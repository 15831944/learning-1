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

#define PORT_SERVER 12345
#define IP_SERVER "127.0.0.1"
#define DIRSIZE 8192
#define NUME_DIRECTOR "."

int main()
{
	char dir[DIRSIZE];
	int sf;
	struct sockaddr_in serv_addr;
	WORD wVE;
	WSADATA wD;
	int we;

}
