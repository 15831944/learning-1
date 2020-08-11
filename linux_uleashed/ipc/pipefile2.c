/*
 * pipefile2.c
 * server for pipe
 *  Created on: Aug 11, 2020
 *      Author: Gabriel Dimitriu
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

FILE *out_file;
char buf[80];

int main() {
	out_file = fopen("a_pipe","w");
	if(out_file == NULL) {
		perror("Error opening pipe");
		exit(1);
	}
	sprintf(buf, "this is test data for the named pipe example\n");
	fwrite(buf,1,80,out_file);
	fclose(out_file);
	exit(0);
}
