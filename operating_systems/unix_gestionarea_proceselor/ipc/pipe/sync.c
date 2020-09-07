/*
 * sync.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "../../common/hdr.h"
#include "sync.h"

static int pfd1[2], pfd2[2];

void config()
{
	if (pipe(pfd1) < 0 || pipe(pfd2) < 0)
		err_sys("Pipe error");
}

void Tell_P(pid_t pid)
{
	if (write(pfd2[1], "s", 1) != 0)
		err_sys("Error write - parent");
}

void Wait_P(void)
{
	char c;
	if (read(pfd1[0], &c, 1) != 1)
		err_sys("Read error");
	if (c != 'p')
		err_quit("Wait_P: incorect data");
}

void Tell_F(pid_t pid)
{
	if (write(pfd1[1],"p", 1) != 1)
		err_sys("Error write - child");
}

void Wait_F(void)
{
	char c;
	if (read(pfd2[0], &c, 1) != 1)
		err_sys("Read error");
	if (c != 's')
		err_quit("Wait_F: incorect data");
}
