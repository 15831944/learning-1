/*
 * popen_ex1.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/wait.h>
#include "../../common/hdr.h"

#define PAGER "${PAGER:-more}"


int main(int argc, char *argv[])
{
	char buf[MAXLINE];
	FILE *fpin, *fpout;
	if (argc !=2)
		err_quit("Usage: %s <path>\n", argv[0]);
	if ((fpin = fopen(argv[1],"r")) == NULL)
		err_sys("Error popen %s", argv[1]);
	if ((fpout = popen(PAGER, "w")) == NULL)
		err_sys("Error popen %s", PAGER);

	while(fgets(buf, MAXLINE, fpin) != NULL) {
		if (fputs(buf, fpout) == EOF)
			err_sys("Error fputs");
	}
	if (ferror(fpin))
		err_sys("Error ferror");
	if (pclose(fpout) == -1)
		err_sys("Error pclose");
	exit(0);
}
