/*
 * callSystem.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <sys/types.h>
#include <sys/wait.h>
#include "../common/hdr.h"
#include "sys.h"
#include "../common/print_exit.h"

int main()
{
	int status;
	if (( status = system("date")) < 0)
		err_sys("System error");
	print_exit(status);
	if ((status = system("Inexisting command")) < 0)
		err_sys("System error");
	if ((status = system("who; exit 77")) < 0)
		err_sys("System error");
	print_exit(status);
	exit(0);
}
