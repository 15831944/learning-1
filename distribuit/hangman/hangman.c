/*
 * hangman.c
 *	server for hangman
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
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>
#include <string.h>

#define ERR(S,N) {fprintf(stderr,"\n\r%s %d\n\r CALL: hangman & \n\r",S,N); exit(N);}

extern time_t time();
extern int errno;
int play_hangman(int, int);
int MaxVieti = 12;
char *cuvinte[] = {
#include "cuvinte.dat"
};

#define PORT_HANGMAN 5432 //telnet port
#define MAXLEN 80 //dim data buffer
#define NUMAR_DE_CUVINTE (sizeof(cuvinte)/sizeof(cuvinte[0]))

int main()
{
	int sock, fd, client_len;
	struct sockaddr_in server; // server address
	struct sockaddr_in client; //client address

	srand((int)time((long *) 0)); // init random
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		ERR("socket", 1);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT_HANGMAN);
	if (bind (sock, (struct sockaddr *) &server, sizeof(server)) < 0)
		ERR("bind", 2);
	listen(sock, 5);
	while(1) {
		client_len = sizeof(client);
		fd = accept(sock, (struct sockaddr *)&client, &client_len);
		if (fd < 0)
			ERR("accept", 3);
		play_hangman(fd, fd);
	}
}

int play_hangman(int in, int out)
{
	char *cuvint_complet, cuvint_partial[MAXLEN];
	char ghicit[MAXLEN], outbuf[MAXLEN];
	int Vieti = MaxVieti;
	int Stare_joc = 'I';
	int i, ghicit_bine, lungime_cuvint;
	char HostName[MAXLEN];

	gethostname(HostName, MAXLEN);
	sprintf(outbuf,"Jucam \"HangMan\" pe masina %s \n\r\n\r", HostName);
	send(out, outbuf, strlen(outbuf), 0);
	/* take one random word */
	cuvint_complet = cuvinte[rand() % NUMAR_DE_CUVINTE];
	lungime_cuvint = strlen(cuvint_complet);
	/* first time no guessed letter */
	for (i = 0; i < lungime_cuvint; i++)
		cuvint_partial[i] = '-';
	cuvint_partial[i] = '\0';
	sprintf(outbuf, " %s %d\n\r", cuvint_partial, Vieti);
	send(out, outbuf, strlen(outbuf), 0);
	while(Stare_joc == 'I') {
		//ask for a letter
		while(recv(in, ghicit, MAXLEN, 0) < 0) {
			if (errno != EINTR)
				ERR("recv", 4);
		}
		ghicit_bine = 0;
		for(i = 0; i < lungime_cuvint;i++) {
			if (ghicit[0] == cuvint_complet[i]) {
				ghicit_bine = 1;
				cuvint_partial[i] = cuvint_complet[i];
			}
		}
		if (!ghicit_bine)
			Vieti--;
		if (strcmp(cuvint_complet, cuvint_partial) == 0)
			Stare_joc = 'W'; //user win
		else if (Vieti == 0) {
			Stare_joc = 'L'; //user lost
			strcpy(cuvint_partial, cuvint_complet); //show the word
		}
		sprintf(outbuf, " %s %d\n\r", cuvint_partial, Vieti);
		send(out,outbuf, strlen(outbuf), 0);
	}
	switch(Stare_joc) {
	case 'W':
		send(out,"\n\rAi cistigat. Felicitari! \n\r\n\r", 31, 0);
		break;
	case 'L':
		send(out,"\n\rAi pierdut. Mai incearca.\n\r\n\r", 31, 0);
	}
}

