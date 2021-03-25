/*
 * udpclient.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 25, 2021
 *      Author: Gabriel Dimitriu
 */


#include "inet.h"

char *pname;
int eroare(char *value)
{
	char tampon[256];
	int len;
	sprintf(tampon,"%s", value);
	len = strlen(tampon);
	sprintf(tampon + len, " %s",strerror(errno));
	fprintf(stderr,"%s\n", tampon);
	return 1;
}

int client(FILE *fp, int dsoclu, struct sockaddr *servadr, int lungserv)
{
	int n;
	char trimis[MAXLINIE], primit[MAXLINIE+1];
	while (fgets(trimis, MAXLINIE, fp) != NULL) {
		n = strlen(trimis);
		if (sendto(dsoclu, trimis, n, 0, servadr, lungserv) != n)
			eroare("client:  eroare la sendto");
		n = recvfrom(dsoclu, primit, MAXLINIE, 0,(struct sockaddr *)0,(int *)0);
		if (n < 0)
			eroare("client: eroare la recvfrom");
		primit[n] = 0;
		fputs(primit, stdout);
	}
	if (ferror(fp))
		eroare("client: eroare la citirea fisierului");
}

int main(int argc, char **argv)
{
	int dsoclu;
	struct sockaddr_in servadr, cliadr;
	pname = argv[0];
	bzero((char *)&servadr, sizeof(servadr));
	servadr.sin_family = AF_INET;
	servadr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
	servadr.sin_port = htons(SERV_UDP_PORT);
	if ((dsoclu = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		eroare("client: nu pot deschide soclul");
	bzero((char *)&cliadr, sizeof(cliadr));
	cliadr.sin_family = AF_INET;
	cliadr.sin_addr.s_addr = htonl(INADDR_ANY);
	cliadr.sin_port = htons(0);
	if (bind(dsoclu, (struct sockaddr *)&cliadr,sizeof(cliadr)) < 0)
		eroare("client: nu pot lega adresa locala");
	client(stdin, dsoclu, (struct sockaddr *)&servadr, sizeof(servadr));
	close(dsoclu);
	exit(0);
}
