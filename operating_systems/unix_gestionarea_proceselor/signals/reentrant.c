/*
 *  reentrant.c
 * it is locked into the signal routine not executing the getpwnam
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */


#include <pwd.h>
#include <signal.h>
#include "../common/hdr.h"

static void sig_alarm(int);

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("This should be called with %s NameOfUser\n", argv[0]);
		exit(-1);
	}
	struct passwd *pw;

	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		err_sys("Error on signal(SIGALARM, ...)");
	alarm(1.75); //do it with 0.5,0.75,1, 1.75
	for(;;) {
		if ((pw = getpwnam(argv[1])) == NULL)
			err_sys("getpwnam error");
		if (strcmp (pw -> pw_name, argv[1]) != 0) {
			printf("Wrong value ! pw_name = %s\n", pw->pw_name);
			fflush(stdout);
		}
	}
}

static void sig_alarm(int sig)
{
	struct passwd *rpw;
	printf("In the signal routine ... \n");
	fflush(stdout);
	if ((rpw = getpwnam("root")) == NULL)
		err_sys("Error getpwnam(root)...");
	printf("User name: %s Pasword: %s\n", rpw->pw_name, rpw->pw_passwd);
	fflush(stdout);
	alarm(1.75);
	return;
}
