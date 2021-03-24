/*
 * utils.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 24, 2021
 *      Author: Gabriel Dimitriu
 */


#include "inet.h"

int citestelinie(int dfisier, char *pointer, int lungmax)
{
	int n,rc;
	char c;
	for (n =1 ; n < lungmax; n++) {
		if ((rc = read(dfisier, &c, 1)) == 1) {
			*pointer++ = c;
			if (c == '\n')
				break;
		} else if (rc == 0) {
			if (n == 1)
				return 0; /* EOF, nu s-a citit nici o data */
			else
				break; /* EOF, s-au citit deja date */
		} else
			return -1; /* eroare */
	}
	*pointer = 0;
	return n;
}

int writen(int dfisier, char *tampon, int nrocteti)
{
	int nroramasi, nroscrisi;
	while (nroramasi > 0) {
		nroscrisi = write(dfisier, tampon, nroramasi);
		if (nroscrisi <= 0)
			return nroscrisi; /* eroare */
		nroramasi -= nroscrisi;
		tampon += nroscrisi;
	}
	return nrocteti - nroramasi;
}
