/*
 * tcpserver.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 24, 2021
 *      Author: Gabriel Dimitriu
 */


/* server orientat pe conexiune, protocol TCP */
#include "inet.h"

char *pname;
int eroare(char *num,...)
{
	va_list args;
	char *fmt;
	char tampon[256];
	int len;
	va_start(args,num);

	fmt = va_arg(args,char *);
	vsprintf(tampon, fmt, args);
	va_end(args);
	len = strlen(tampon);
	sprintf(tampon + len, " %s",strerror(errno));
	syslog(LOG_ERR, tampon);
	return 1;
}

int ecou(int dsoclu)
{
	int n;
	char linie[MAXLINIE];

	for(;;) {
		n = citestelinie(dsoclu, linie, MAXLINIE);
		if (n == 0) /* conexiune terminata */
			return 0;
		else if (n < 0)
			eroare("ecou: eroare la citirea liniei");
		if (writen(dsoclu, linie, n) != n)
			eroare("ecou: eroare la scriere");
	}
	return 1;
}

int main(int argc, char **argv)
{
	int dsoclu, dsoclunou, lungcli, pidcopil;
	struct sockaddr_in cliadr, servadr;

	pname = argv[0];
	if ((dsoclu = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		eroare("server: nu pot deschide soclul");
	bzero((char *)&servadr, sizeof(servadr));
	servadr.sin_family = AF_INET;
	servadr.sin_addr.s_addr = htonl(INADDR_ANY);
	servadr.sin_port = htons(SERV_TCP_PORT);
	if ( bind(dsoclu, (struct sockaddr *)&servadr,sizeof(servadr)) < 0)
		eroare("server: nu pot lega adresa locala");
	listen(dsoclu,5);
	for(;;) {
		lungcli = sizeof(cliadr);
		dsoclunou = accept(dsoclu, (struct sockaddr *)&cliadr, &lungcli);
		if (dsoclunou < 0)
			eroare("server: eroare la accept");
		if ((pidcopil = fork()) < 0)
			eroare("server: eroare la fork");
		else if (pidcopil == 0) {
			close(dsoclu);
			ecou(dsoclunou);
			exit(0);
		}
		close(dsoclu);
	}
}
