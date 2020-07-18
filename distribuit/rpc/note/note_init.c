/*
 * note_init.c
 *
 *  Created on: Jul 16, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "note.h"

int main()
{
	int i,f;
	note_t A;
	char s[256];
	memset(A.Uid, 0, LUNGART);
	if ((f = open(FILE_NOTE, O_CREAT | O_WRONLY, 0644)) < 0)
		return 1;
	for(i = 0; i < MAX_UID; i++)
		write(f, A.Uid, LUNGART);
	close(f);
	sprintf(s, "\nIn \"%s\" %d pozitii (%ld octeti) nule\n", FILE_NOTE, MAX_UID, MAX_UID*LUNGART);
	P(s);
}
