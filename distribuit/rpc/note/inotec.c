/*
 * inote.c
 *
 *  Created on: Jul 18, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "note.h"
#include "xdr.h"
#include <sys/socket.h>
#include <memory.h>

#define LINIE (LUNGART + 2 * NRNOTE)
struct timeval timeout = {25,25};

int main(int argc, char *argv[])
{
	int i, R;
	char linie[LINIE], Uid[LUNGUID], *Server, Actiune, *p, *q;
	enum clnt_stat v;
	CLIENT *canal;
	note_t A;
	Server = argv[1];
	canal = clnt_create(Server, PROGRAM_NOTE, VERSIUNE_NOTE, "udp");
	if (canal == NULL) {
		clnt_pcreateerror(Server);
		return 1;
	}
	canal -> cl_auth = authunix_create_default();
	for (;;) {
			if (fgets(linie, LINIE, stdin) == NULL)
				break;
			P(linie);
			memset(A.Uid, 0, LUNGART);
			p = linie + 2;
			if ((q = memchr(p, '\t', LINIE)) != NULL) {
				sscanf(p, "%s\t", A.Uid);
				p = q + 1;
			}
			for (i = 0; i < NRNOTE; i++) {
				if ((q = memchr(p, '\t', LINIE)) != NULL) {
					sscanf(p, "%d\t", &A.Tema[i]);
					p = q + 1;
				}
				if ((q = memchr(p, '\t', LINIE)) != NULL) {
					sscanf(p, "%d\t", &A.Nota[i]);
					p = q + 1;
				}
			}
			if (memchr(p, '\t', LINIE) != NULL)
				sscanf(p, "%s\t", A.Obs);
			Actiune = linie[0];
			strcpy(Uid, A.Uid);
			Actiune = linie[0];
			if (A.Uid[0] == 0)
				Actiune = 'E';
			printf("\nUid 			: %s", Uid);
			switch (Actiune) {
			case 'g':
			case 'G':
				if ((v = clnt_call(canal, GET_NOTE, xdr_Uid, Uid, xdr_note_t, A.Uid, timeout)) != 0) {
					clnt_perrno(v);
					P("\"get_note\" ERROARE callrpc");
					return 1;
				}
				P("S-a gasit:");
				break;
			case 'p':
			case 'P':
				if ((v = clnt_call(canal, PUT_NOTE, xdr_note_t, A.Uid, xdr_Uid, Uid, timeout)) != 0) {
					clnt_perrno(v);
					P("\"put_note\" ERROARE callrpc");
					return 1;
				}
				P("S-a adugat:");
				break;
			case 'd':
			case 'D':
				if ((v = clnt_call(canal, DEL_NOTE, xdr_Uid, Uid, xdr_note_t, A.Uid, timeout)) != 0) {
					clnt_perrno(v);
					P("\"del_note\" EROARE callrpc");
					return 1;
				}
				P("S-a sters");
				break;
			default:
				P("Linie de intrare eronata; se ignora");
			}
			printf("\nA.Uid 	:%s\nTeme si note:\n", A.Uid);
			for (i = 0; i < NRNOTE; i++)
				printf(" %d %d ", A.Tema[i], A.Nota[i]);
			printf("\nObservatii   : %s\n", A.Obs);
		}
	clnt_destroy(canal);
}
