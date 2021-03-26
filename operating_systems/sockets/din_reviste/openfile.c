/*
 * openfile.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 26, 2021
 *      Author: Gabriel Dimitriu
 */


/*
 * server that send file open descriptor to child
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "openfile.h"

int main(int argc, char **argv)
{
	int fd;
	if (argc !=4) {
		printf("%s <dsoclu> <nume fisier> <mod>\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[2], atoi(argv[3]))) < 0)
		exit((errno >0) ? errno : 255);
	exit(sendfile(atoi(argv[1]), fd));
}
