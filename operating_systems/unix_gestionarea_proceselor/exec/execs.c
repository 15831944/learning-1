/*
 * execs.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include "execs.h"

int execs(const char *cmdlin)
{
	const char *delim=",. ";
	char *tcmdlin = NULL;
	int argc = 0;
	char **argv = NULL;
	char *p = NULL;
	tcmdlin = (char *)calloc((size_t)(strlen(cmdlin) + 1), sizeof(*tcmdlin));
	strcpy(tcmdlin, cmdlin);
	argc = 0;
	argv = NULL;
	p = strtok(tcmdlin, delim);
	while(1) {
		argv = (char **)realloc(argv,(size_t)((argc+1)*sizeof(*argv)));
		if (p == NULL) {
			argv[argc] = NULL;
			break;
		}
		argv[argc] = (char *)calloc((size_t)(strlen(p)+1),sizeof(*argv[argc]));
		strcpy(argv[argc++],p);
		p = strtok(NULL, delim);
	}
	execv(argv[0], argv);
	while(--argc>=0)
		free(argv[argc]);
	free(argv);
	free(tcmdlin);
	return -1;
}
