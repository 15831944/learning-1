/*
 * dlerrtest.c
 * dynamically oad liberr.so
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void) {
	void *handle;
	void (*errfcn)();
	const char *errmsg;
	FILE *pf;
	handle = dlopen("liberr.so", RTLD_NOW);
	if (handle == NULL) {
		fprintf(stderr,"Failed to load liberr.so: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	dlerror();
	errfcn = dlsym(handle, "err_ret");
	if ((errmsg = dlerror()) != NULL) {
		fprintf(stderr, "Didn't find err_ret(): %s\n", errmsg);
		exit(EXIT_FAILURE);
	}
	if ((pf = fopen("foobar", "r")) == NULL) {
		errfcn("Couldn't open foobar");
	}
	dlclose(handle);
	return EXIT_SUCCESS;
}
