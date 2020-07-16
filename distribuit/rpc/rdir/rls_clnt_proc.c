/*
 * rls_clnt_proc.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include <stdio.h>
#include <rpc/rpc.h>
#include "rls.h"
#include <stdlib.h>
#include <errno.h>

extern int errno;
int main(int argc, char *argv[])
{
	CLIENT *cl;
	char *server, *dir;
	readdir_res *result;
	namelist nl;
	if (argc != 3) {
		fprintf(stderr, "Usage: %s machine folder\n", argv[0]);
		exit(1);
	}
	server = argv[1];
	dir = argv[2];
	/* create a handle client for remote request, we use tcp */
	cl = clnt_create(server, DIRPROG, DIRVERS, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(server);
		exit(1);
	}
	/* call remote procedure */
	result = readdir_1(&dir, cl);
	if (result == NULL) {
		//error on call to the server
		clnt_perror(cl, server);
		exit(1);
	}
	/* call with success */
/*	if (result -> errno != 0) {
		//we have an error to rezumat
		errno = result->errno;
		perror(dir);
		exit(1);
	} */
	/* print the result */
	for (nl = result -> readdir_res_u.list; nl != NULL; nl = nl -> pNext) {
		printf("%s\n", nl -> name);
	}
	exit(0);
}
