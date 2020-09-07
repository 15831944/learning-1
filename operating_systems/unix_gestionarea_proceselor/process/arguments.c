/*
 * arguments.c
 * arguments and environment variables
 *  Created on: Aug 30, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
int main(int argc, char *argv[], char *envp[])
{
	int k;
	for(k = 0; k < argc; ++k)
		printf("parameter nr %d is : %s\n",k, argv[k]);
	fflush(stdout);
	for (k = 0; ; k++)
		if (envp[k] != NULL) {
			printf("environment variable from arguments in main nr %d is: %s\n",k, envp[k]);
		}
		else
			break;
	fflush(stdout);
	for (k = 0; ; k++)
			if (environ[k] != NULL) {
				printf("environment variable from external variable nr %d is: %s\n",k, environ[k]);
			}
			else
				break;
	fflush(stdout);
	char *home;
	if ((home = getenv("HOME")) == NULL)
	{
		printf("HOME variable is not defined!\n");
		exit(1);
	} else {
		printf("HOME=%s\n",home);
	}
}
