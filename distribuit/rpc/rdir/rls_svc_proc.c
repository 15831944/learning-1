/*
 * rls_svc_proc.c
 * implements the remote procedure call
 *  Created on: Jul 15, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include <stdio.h>
#include <rpc/rpc.h>
#include <sys/dir.h>
#include "rls.h"
#include <errno.h>

extern int errno;

readdir_res * readdir_1(nametype *dirname)
{
	namelist nl, *nlp;
	static readdir_res res; /* it must be static */
	static DIR *dirp = NULL; /* it must be static to see that it was called once */
	struct direct *d;
	/* open a folder */
	dirp = opendir(*dirname);
	if (dirp == NULL) {
//		res.errno = errno;
		return (&res);
	}
	/* free the previous call because it could be a big list which use a lot of memory */
	if(dirp)
		xdr_free(xdr_readdir_res, &res);
	/*
	 * collect and print files from directory.
	 * the memory will be release at next call
	 */
	nlp = &res.readdir_res_u.list;
	while((d = readdir(dirp))) {
		nl = *nlp = (namenode *)malloc(sizeof(namenode));
		nl -> name = strdup(d -> d_name);
		nlp = &nl -> pNext;
	}
	*nlp = NULL;
	/* return the result */
//	res.errno = 0;
	closedir(dirp);
	return &res;
}
