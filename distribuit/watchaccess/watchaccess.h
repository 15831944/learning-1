/*
 * watchaccess.h
 *
 *  Created on: Jul 13, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#ifndef WATCHACCESS_WATCHACCESS_H_
#define WATCHACCESS_WATCHACCESS_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

extern int errno;
#define PORT_CONSTATARE 2222
#define PORT_INTERVENTIE 3333
#define MAX 255
#define ERR(S,N) {fprintf(stderr,"%d ",N);perror(S); exit(N);}
#define MES(S,N) {fprintf(stderr,"\n %s %d \n",S, N); }

/* Send on socket s from address t n characters, it could be send on chunks */
int Send(int s, char *t, int n);

/* receive from socket s from address t n characters, it could receive on chunks */
int Recv(int s, char *t, int n);

union M {
	short I[4];// minimum 4 ints
	char S[1]; // maximum 1 string
};
typedef union M Mesaj;

Mesaj * Alloc(int LT);
// delete the message allocated by Alloc
int Delete(Mesaj *m);
// validate the structure of the message
int Valid(Mesaj *m);
// put value v at integer i form m
int AtribuireI(Mesaj *m, int i, int v);
//get the value of integer i from m
int ValoareI(Mesaj *m, int i);
//put string value s at i from m
int AtribuireS(Mesaj *m, int i, char *s);
//get the pointer to the string i from m
char *ValoareS(Mesaj *m, int i);
#endif /* WATCHACCESS_WATCHACCESS_H_ */
