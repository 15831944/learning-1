/*
 * pipefile1.c
 * client for pipe
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

FILE *in_file;
char buf[80];

int main() {
	in_file = fopen("a_pipe", "r");
	if (in_file == NULL) {
		perror("Error in fopen");
		exit(1);
	}
	fread(buf,1,80,in_file);
	printf("received from pipe: %s\n", buf);
	fclose(in_file);
	exit(0);
}
