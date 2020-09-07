/*
 * coprocess.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include "../../common/hdr.h"

int main(void)
{
	int n, n1, n2;
	char buf[MAXLINE];
	char merr[] ="Invalid aruments!\n";

	while((n = read(0, buf, MAXLINE)) > 0) {
		buf[n] = '\0';
		if (sscanf(buf,"%d%d", &n1, &n2) == 2) {
			sprintf(buf, "%d\n", n1+n2);
			n = strlen(buf);
			if (write(1, buf, n) != n)
				err_sys("Write error");
		}
		else
			if (write(1,merr, strlen(merr)) != strlen(merr))
				err_sys("Write error");
	}
	exit(0);
}
