/*
 * tcpclient.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 25, 2021
 *      Author: Gabriel Dimitriu
 */


#include "inet.h"
char *pname;

int eroare(char * value)
{
	fprintf(stderr,"value=%s\n", value);
	fprintf(stderr," %s\n",strerror(errno));
	exit(1);
}

int client(FILE *fp, int dsoclu)
{
	int n;
	char trimis[MAXLINIE], primit[MAXLINIE+1];
	while(fgets(trimis, MAXLINIE, fp) != NULL) {
		n = strlen(trimis);
		if (writen(dsoclu, trimis, n) != n)
			eroare("client: eroare la scriere in soclu");
		n = citestelinie(dsoclu, primit, MAXLINIE);
		if (n < 0)
			eroare("client: eroare la citirea liniei");
		primit[n] = 0;
		fputs(primit, stdout);
	}
	if (ferror(fp))
		eroare("client: eroare la citirea fisierului");
	return 1;
}

int main(int argc, char **argv)
{
	int dsoclu;
	struct sockaddr_in servadr;
	pname = argv[0];
	bzero((char *)&servadr, sizeof(servadr));
	servadr.sin_family = AF_INET;
	servadr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
	servadr.sin_port = htons(SERV_TCP_PORT);
	if ((dsoclu = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		eroare("client: nu pot deschide soclul");
	if (connect(dsoclu, (struct sockaddr *)&servadr, sizeof(servadr)) < 0)
		eroare("client: nu ma pot connecta la server");
	client(stdin, dsoclu);
	close(dsoclu);
	exit(0);
}
