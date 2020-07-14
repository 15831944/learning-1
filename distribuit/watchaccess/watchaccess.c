/*
 * watchaccess.c
 *
 *  Created on: Jul 13, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "watchaccess.h"

int Send(int s, char *t, int n)
{
	int c;
	for(;n > 0;) {
		c = send(s,t,n,0);
		if (c < 0)
			return -1;
		n -= c;
		t += c;
	}
	return 0;
}

int Recv(int s, char *t, int n)
{
	int c;
	for (;n > 0;) {
		c = recv(s,t,n,0);
		if (c <=0 )
			return -1;
		n -=c;
		t +=c;
	}
	return 0;
}

Mesaj * Alloc(int LT)
{
	Mesaj *p;
	if (LT < 4 *sizeof(short)) {
		MES("Alloc", 1);
		return NULL;
	}
	p = (Mesaj *) malloc(LT);
	if (p == NULL) {
		MES("Alloc", 2);
		return NULL;
	}
	memset(p, 0, LT);
	*((short *) p ) = htons((short) LT);
	return p;
}

int Delete(Mesaj *m)
{
	if (!Valid(m)) {
		MES("Delete", 3);
		return 0;
	}
	free((char *)m);
	return 1;
}

int Valid(Mesaj *m)
{
	int LT, NI, NS, i,k;
	char *p;
	LT = ValoareI(m,0);
	NI = ValoareI(m,1);
	NS = ValoareI(m,2);
	if (( LT < 4 * sizeof(short)) || (NI < 1) || (NS < 1)) {
		MES("Valid",4);
		return 0;
	}
	for ( i = 0; i < NI; i++)
		if (ValoareI(m,i) < 0) {
			MES("Valid", 5);
			return 0;
		}
	if (*((char *) m + LT -1) != 0) {
		MES("Valid", 6);
		return 0;
	}
	k = 0;
	for (i = (NI + 3) * sizeof(short), k = 0 , p = (char *)m; i < LT; i++)
		if(*(p + i) == 0)
			k++;
	if ( k != NS) {
		MES("Valid", 7);
		return 0;
	}
}

int AtribuireI(Mesaj *m, int i, int v)
{
	short NI;
	NI = ValoareI (m, 1);
	if ((v < 0) || (i < 0) || (i >= 3 * NI)) {
		MES("AtribuireI", 8);
		return 0;
	}
	(m -> I[i]) = htons((short) v);
	return 1;
}
int ValoareI(Mesaj *m, int i)
{
	short NI;
	NI = ntohs(m -> I[1]);
	if ((i < 0) || (i >= 3 + NI)) {
		MES("ValoareI", 9);
		return -1;
	}
	return ntohs(m -> I[i]);
}

int AtribuireS(Mesaj *m, int i, char *s)
{
	int NI, NS, k;
	char *p;
	NI = ValoareI(m,1);
	NS = ValoareI(m,2);
	if (s == NULL) {
		MES("AtribuireS", 10);
		return 0;
	}
	if ((i < 0) || (i >= NS)) {
		MES("AtribuireS", 11);
		return 0;
	}
	p = (char *)m + (NI + 3) * sizeof(short);
	for(k = 0; k < i; k++)
		p += strlen(p) + 1;
	strcpy(p,s);
	return 1;
}

char *ValoareS(Mesaj *m, int i)
{
	short NI, NS, k;
	char *p;
	NI = ValoareI(m,1);
	NS = ValoareI(m,2);
	if (( i < 0) || (i >= NS)) {
		MES("ValoareS", 12);
		return NULL;
	}
	p = (char *)m + (NI + 3) * sizeof(short);
	for (k = 0; k < i; k++)
		p += strlen(p) + 1;
	return p;
}
