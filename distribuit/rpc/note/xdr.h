/*
 * xdr.h
 *
 *  Created on: Jul 16, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */
#include "note.h"

#ifndef RPC_NOTE_XDR_H_
#define RPC_NOTE_XDR_H_

int xdr_Uid(struct XDR *xdr_hp, void *op);
int xdr_note_t(struct XDR *xdr_hp, void *opin);



#endif /* RPC_NOTE_XDR_H_ */
