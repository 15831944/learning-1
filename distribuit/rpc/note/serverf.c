/*
 * serverf.c
 *
 *  Created on: Jul 18, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "serverf.h"

char *put_note(note_t *Art)
{
	static note_t A;
	int i,f;
	P("put note");
	if((f = open(FILE_NOTE, O_RDWR)) < 0)
		goto ERR;
	for ( i = 0; i < MAX_UID; i++) {
		read(f, A.Uid, LUNGART);
		if (A.Uid[0])
			continue;
		lseek(f, (long)(i) * LUNGART, SEEK_SET);
		write(f, Art -> Uid, LUNGART);
		close(f);
		memcpy(A.Uid, Art -> Uid, LUNGUID);
		return A.Uid;
	}
	close(f);
	ERR:
		memset(A.Uid, 0, LUNGUID);
		return A.Uid;
}

char *get_note(char *Uid)
{
	static note_t A;
	int i,f;
	P("get_note");
	if ((f = open(FILE_NOTE, O_RDONLY )) < 0)
		goto ERR;
	for(i = 0; i < MAX_UID; i++) {
		read(f, A.Uid, LUNGART);
		if (!strcmp(Uid, A.Uid)) {
			close(f);
			return A.Uid;
		}
	}
	close(f);
	ERR:
		memset(A.Uid, 0, LUNGART);
		return A.Uid;
}

char *del_note(char *Uid)
{
	static note_t A;
	note_t B;
	int i,f;
	P("del_note");
	if ((f = open(FILE_NOTE, O_RDWR)) < 0)
		goto ERR;
	for (i = 0; i < MAX_UID; i++) {
		read(f, A.Uid, LUNGART);
		if (strcmp(Uid, A.Uid))
			continue;
		memset(B.Uid, 0, LUNGART);
		lseek(f, (long) (i) * LUNGART, SEEK_SET);
		write(f, B.Uid, LUNGART);
		close(f);
		return A.Uid;
	}
	close(f);
	ERR:
		memset(A.Uid, 0, LUNGART);
		return A.Uid;
}
