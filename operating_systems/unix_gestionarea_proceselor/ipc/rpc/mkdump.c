/*
 * mkdump.c
 * make dump of encoding file
 *  Created on: Sep 11, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <rpc/types.h>
#include <rpc/xdr.h>
#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>

int main(int argc, char **argv)
{
	int f = 0;
	FILE *fp;
	XDR h;
	struct utmp *up;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s infile encodefile\n", argv[0]);
		exit(1);
	}
	if (utmpname(argv[1]) != 1) {
		fprintf(stderr, "%s filename is too long\n", argv[1]);
		exit(1);
	}
	if ((fp = fopen(argv[2],"w")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(1);
	}

	xdrstdio_create(&h, fp, XDR_ENCODE);

	while((up = getutent()) != NULL) {
		if (xdr_vector(&h, up -> ut_user, sizeof(up->ut_user), sizeof(char), (xdrproc_t) xdr_char) == FALSE) {
			f = 1;
			break;
		}
		if (xdr_vector(&h, up -> ut_id, sizeof(up->ut_id), sizeof(char), (xdrproc_t)xdr_char) == FALSE) {
			f = 2;
			break;
		}
		if (xdr_vector(&h, up->ut_line, sizeof(up->ut_line), sizeof(char), (xdrproc_t)xdr_char) == FALSE) {
			f = 3;
			break;
		}
		if (xdr_short(&h, (short *)&up->ut_pid) == FALSE) {
			f = 4;
			break;
		}
		if (xdr_short(&h, &up->ut_type) == FALSE) {
			f = 5;
			break;
		}
		if (xdr_short(&h, &up->ut_exit.e_termination) == FALSE) {
			f = 6;
			break;
		}
		if (xdr_short(&h, &up->ut_exit.e_exit) == FALSE) {
			f = 7;
			break;
		}
		if (xdr_int(&h,&up->ut_time) == FALSE) {
			f = 8;
			break;
		}
	}
	if (f != 0) {
		fprintf(stderr, "%s: XDR error %d at transaltion\n",argv[0], f);
		exit(1);
	}
}
