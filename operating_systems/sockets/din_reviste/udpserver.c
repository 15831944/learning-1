/*
 * udpserver.c
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

int ecou(int dsoclu, struct sockaddr *cliadr, int lungmaxcli) {
	int n, lungcli;
	char mesaj[MAXMESAJ];

	for(;;) {
		lungcli = lungmaxcli;
		n = recvfrom(dsoclu, mesaj, MAXMESAJ, 0, cliadr,&lungcli);
		if (n < 0)
			eroare("ecou: eroare la recvfrom");
		if (sendto(dsoclu, mesaj, n, 0, cliadr, lungcli) < 0)
			eroare("ecou: eroare la sendto");
	}
	return 0;
}

int main(int argc, char **argv) {
	int dsoclu;
	struct sockaddr_in cliadr, servadr;
	pname = argv[0];
	if((dsoclu = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		eroare("server: nu pot deschide soclul");
	bzero((char *)&servadr, sizeof(servadr));
	servadr.sin_family = AF_INET;
	servadr.sin_addr.s_addr = htonl(INADDR_ANY);
	servadr.sin_port = htons(SERV_UDP_PORT);
	if (bind(dsoclu,(struct sockaddr *)&servadr, sizeof(servadr)) < 0)
		eroare("server: nu put lega adresa locala");
	ecou(dsoclu, (struct sockaddr *)&cliadr, sizeof(cliadr));

}
