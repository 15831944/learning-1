/*
 * note_svc.c
 *
 *  Created on: Jul 16, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "note.h"
#include "xdr.h"
#include <rpc/svc.h>
#include <memory.h>
#include "serverf.h"

#define LINIE (LUNGART + 2*NRNOTE)

int main()
{
	if (registerrpc(PROGRAM_NOTE, VERSIUNE_NOTE, GET_NOTE, get_note, xdr_Uid, xdr_note_t) < 0) {
		P("Eroare la inregistrare \"get note\"");
		return 1;
	}
	if (registerrpc(PROGRAM_NOTE, VERSIUNE_NOTE, PUT_NOTE, put_note, xdr_note_t, xdr_Uid) < 0) {
		P("Eroare la inregistare \"put note\"");
		return 1;
	}
	if (registerrpc(PROGRAM_NOTE, VERSIUNE_NOTE, DEL_NOTE, del_note, xdr_Uid, xdr_note_t) < 0) {
		P("Eroare la inregistrare \"del_note\"");
		return 1;
	}
	svc_run();
}
