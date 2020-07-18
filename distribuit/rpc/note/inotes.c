/*
 * inotes.c
 *
 *  Created on: Jul 18, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "note.h"
#include "serverf.h"
#include "xdr.h"
#include <sys/socket.h>
#include <netdb.h>

#define GID_EXCLUS 30
void Dispecer(struct svc_req *cerere, SVCXPRT *transport);
int main() {
	SVCXPRT *transport;

	/* get support for transport */
	transport = svcudp_create(RPC_ANYSOCK);
	if (transport == NULL) {
		fprintf(stderr, " Eroare la svcudp_create");
		return 1;
	}
	/* register the service in portmapper */
	(void) pmap_unset(PROGRAM_NOTE, VERSIUNE_NOTE);
	if (svc_register(transport, PROGRAM_NOTE, VERSIUNE_NOTE, Dispecer,
			IPPROTO_UDP) == FALSE) {
		fprintf(stderr, "Eroare la svc_register");
		svc_destroy(transport);
		return 1;
	}
	/* call the library to dispatch RPC */
	svc_run();
	fprintf(stderr, "Eroare la svc_run");
	svc_unregister(PROGRAM_NOTE, VERSIUNE_NOTE);
	svc_destroy(transport);
	return 1;
}

void Dispecer(struct svc_req *cerere, SVCXPRT *transport) {
	char Uid[LUNGUID];
	note_t A;
	struct authunix_parms *credentials;
	P("Dispecer");
	if (cerere->rq_cred.oa_flavor != AUTH_UNIX) {
		svcerr_weakauth(transport);
		P("Nu s-a cerut authentificare UNIX");
	}
	switch (cerere->rq_proc) {
	case NULLPROC:
		svc_sendreply(transport, xdr_void, 0);
		return;
	case GET_NOTE:
		if (svc_getargs(transport, xdr_Uid, Uid) == FALSE) {
			svcerr_decode(transport);
			return;
		}
		memcpy(A.Uid, get_note(Uid), LUNGART);
		if (svc_sendreply(transport, xdr_note_t, A.Uid) == FALSE) {
			svcerr_systemerr(transport);
		}
		break;
	case PUT_NOTE:
		credentials = (struct authunix_params*) cerere->rq_clntcred;
		if (credentials->aup_gid == GID_EXCLUS) {
			P("Acest GID nu are voie sa faca \"put_note\"");
			return;
		}
		if (svc_getargs(transport, xdr_note_t, A.Uid) == FALSE) {
			svcerr_decode(transport);
			return;
		}
		memcpy(Uid, put_note(&A), LUNGUID);
		if (svc_sendreply(transport, xdr_Uid, Uid) == FALSE) {
			svcerr_systemerr(transport);
		}
		break;
	case DEL_NOTE:
		credentials = (struct authunix_params*) cerere->rq_clntcred;
		if (credentials->aup_gid == GID_EXCLUS) {
			P("Acest GID nu are voie sa faca \"del_note\"");
			return;
		}
		if (svc_getargs(transport, xdr_Uid, Uid) == FALSE) {
			svcerr_decode(transport);
			return;
		}
		memcpy(Uid, del_note(Uid), LUNGUID);
		if (svc_sendreply(transport, xdr_note_t, A.Uid) == FALSE) {
			svcerr_systemerr(transport);
		}
		break;
	default:
		svcerr_noproc(transport);
		break;
	}
}
