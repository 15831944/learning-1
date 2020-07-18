/*
 * note.h
 *
 *  Created on: Jul 16, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#ifndef RPC_NOTE_NOTE_H_
#define RPC_NOTE_NOTE_H_

#include <stdio.h>
#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define PROGRAM_NOTE ((u_long)0x40000000)
#define VERSIUNE_NOTE ((u_long)1)
#define GET_NOTE ((u_long)1)
#define PUT_NOTE ((u_long)2)
#define DEL_NOTE ((u_long)3)

#define LUNGOBS 8
#define LUNGUID 8
#define NRNOTE 2
#define FILE_NOTE "note.dat"
#define MAX_UID 1000 /*maximum number of students into the file */

typedef struct {
	char Uid[LUNGUID]; //user indentifier
	int Tema[NRNOTE]; //number of homework
	int Nota[NRNOTE]; //the grad
	char Obs[LUNGOBS]; //observations
} note_t;

#define LUNGART (sizeof(note_t))
void P(char *s);


#endif /* RPC_NOTE_NOTE_H_ */
