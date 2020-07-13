/*
 * warehouse.c
 * warehouse stock control
 *  Created on: Jul 13, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

extern int errno;
#define ERR(S,N) {fprintf(stderr,"\n%d\n",N); perror(S); exit(N);}
#define PORT_STOC 7777

int prelucrare_stoc(FILE *stream, int fd);
/* structure of the stock position */
struct element_stoc {
	char produs[32]; //name of the product
	long cantitate; // quantity
};
/* database for stocks */
#define MAX_POZITII 1000 // number of the positions in stock
struct element_stoc lista_stocuri[MAX_POZITII];
int main()
{
	int sock, fd, addrlen;
	struct sockaddr_in server, client;
	int max_fd;
	FILE **stream;
	struct rlimit limit_info;
	/* number of descriptors use by select */
	fd_set test_set, ready_set;
	/* this will be dynamically allocated using the number from getrlimit() */
	if (getrlimit(RLIMIT_NOFILE, &limit_info)  < 0)
		ERR("getrlimit", 1);
	if ((stream = (FILE **)malloc(limit_info.rlim_cur * sizeof(FILE *))) < 0)
		ERR("malloc",2);
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR("socket",3);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT_STOC);
	if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
		ERR("bind", 4);
	listen(sock, 5);
	max_fd = sock;
	/* initially test_set has only the meeting descriptor */
	FD_ZERO(&test_set);
	FD_SET(sock, &test_set);
	/* end of the list is marked by -1 */
	lista_stocuri[0].cantitate = -1;
	//main loop
	for(;;) {
		/* because select override the list of descriptors we have to use a copy */
		memcpy(&ready_set, &test_set, sizeof(test_set));
		select(max_fd + 1, &ready_set, NULL, NULL, NULL);
		/* do we have a new request then is accepted and added to descriptors set */
		if (FD_ISSET(sock, &ready_set)) {
			addrlen = sizeof(client);
			fd = accept(sock, (struct sockaddr *)&client, &addrlen);
			FD_SET(fd, &test_set);
			if (fd > max_fd)
				max_fd = fd;
			stream[fd] = fdopen(fd, "r+");
		}
		/* now we check each descriptor to see if we have a request */
		for(fd = 0; fd <= max_fd; fd++) {
			if ((fd != sock) && FD_ISSET(fd,&ready_set)) {
				if(prelucrare_stoc(stream[fd], fd) >= 0) {
					fflush(stream[fd]);
				}
				else {
					/* if the client has closed the connection we should remove */
					close(fd);
					FD_CLR(fd, &test_set);
				}
			}
		}
	}
}
int prelucrare_stoc(FILE *stream, int fd)
{
	/* return 0 if everything is ok otherwise -1 for EOF from client */
	enum {
		INTRARE, IESIRE, STOC, STOP, ILEGAL
	} Operatie;
	char buffer_cerere[100];
	char cerere[32];
	char produs[32];
	long cantitate;
	struct element_stoc *p;
	/* read the request from client */
	if (fgets(buffer_cerere, 100, stream) == NULL)
		return -1;
	sscanf(buffer_cerere, "%s %s %ld", cerere, produs, &cantitate);
	Operatie = ILEGAL;
	if (strcmp(cerere, "INTRARE") == 0)
		Operatie = INTRARE;
	else if (strcmp(cerere, "IESIRE") == 0)
		Operatie = IESIRE;
	else if (strcmp(cerere, "STOC") == 0)
		Operatie = STOC;
	else if (strcmp(cerere, "STOP") == 0)
		Operatie = STOP;
	for (p = lista_stocuri; p -> cantitate >= 0; p++)
		if(strcmp(produs, p -> produs) == 0)
			break;
	if (p -> cantitate < 0)
		p = NULL;
	switch(Operatie) {
	case INTRARE:
		if (p != NULL) {
			p -> cantitate += cantitate;
		}
		else {
			for (p = lista_stocuri; p -> cantitate >= 0; p++);
			if (p - lista_stocuri > MAX_POZITII -1)
				ERR("Depasire spatiu", p - lista_stocuri);
			strcpy(p -> produs, produs);
			p -> cantitate = cantitate;
			/* mark the end of the list */
			(p + 1) -> cantitate = -1;
		}
		fprintf(stream, "A instrat %s %ld\n\r", produs, cantitate);
		return 0; //INTRARE
	case IESIRE:
		if (p != NULL) {
			/* check if we have enough products */
			if (p -> cantitate >= cantitate) {
				fprintf(stream, "Livrat %s %ld\n\r", produs, cantitate);
				p -> cantitate -= cantitate;
			}
			else {
				fprintf(stream, "Livrat %s %ld\n\r", produs, p -> cantitate);
				p -> cantitate = 0;
			}
		}
		else {
			fprintf(stream, "ERROR: produsul %s este necunoscut!\n\r", produs);
		}
		return 0; //IESIRE
	case STOC:
		if (p != NULL) {
			fprintf(stream, "Stocul %s %ld\n\r", produs, p -> cantitate);
		}
		else {
			fprintf(stream, "ERROR: produsul %s este necunoscut!\n\r", produs);
		}
		return 0;
	case STOP:
		fprintf(stream,"STOP. Closing connection!\n\r");
		return -1;
	default:
		fprintf(stream,"ERROR: tp de cerere necunoscut !\n\r");
		return 0;
	}
}
