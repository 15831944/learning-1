/*
 * limits.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "../common/hdr.h"
static void print_limits(char *, int);

#define doit(name) print_limits(#name, name)



int main(void)
{
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_FSIZE);
#ifdef RLIMIT_NOFILE //SRV4
	doit(RLIMIT_NOFILE);
#endif
#ifdef RLIMIT_OFILE // 4.3-BSD
	doit(RLIMIT_OFILE);
#endif
	exit(0);
}

static void print_limits(char *name , int res)
{
	struct rlimit limita;
	if (getrlimit(res, &limita) < 0)
		err_sys("Error getrlimit for %s", name);
	printf("%-14s\t", name);
	if (limita.rlim_cur == RLIM_INFINITY)
		printf("(infinte)\t");
	else
		printf("%10ld\t",limita.rlim_cur);
	if (limita.rlim_max == RLIM_INFINITY)
		printf("(infinite)\n");
	else
		printf("%10ld\n", limita.rlim_max);
}
