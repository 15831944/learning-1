/*
 * serverf.h
 *
 *  Created on: Jul 18, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */
#include "note.h"

#ifndef RPC_NOTE_SERVERF_H_
#define RPC_NOTE_SERVERF_H_

char *put_note(note_t *Art);
char *get_note(char *Uid);
char *del_note(char *Uid);


#endif /* RPC_NOTE_SERVERF_H_ */
