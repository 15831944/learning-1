/*
 * xdr.c
 *
 *  Created on: Jul 16, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "xdr.h"

int xdr_Uid(struct XDR *xdr_hp, void *opin)
{
	P("xdr_Uid");
	char *op = (char *)opin;
	return xdr_string(xdr_hp,&op, LUNGUID);
}

int xdr_note_t(struct XDR *xdr_hp, void *opin)
{
	bool_t B;
	note_t *op = (note_t *)opin;
	int i;
	char *p, *q;

	P("xdr_note_t");
	p = op -> Uid;
	q = op -> Obs;
	B = xdr_string(xdr_hp, &p, LUNGUID) && xdr_string(xdr_hp, &q, LUNGOBS);
	for(i = 0; i < NRNOTE; i++) {
		B = B && xdr_int(xdr_hp, &(op -> Tema[i])) && xdr_int(xdr_hp, &(op -> Nota[i]));
	}
	return B;
}

