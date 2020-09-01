/*
 * times.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Processlor by Iosif Ignat and Adrian Kacso
 */

#include <sys/times.h>
#include "../common/hdr.h"
#include "../common/print_exit.h"

static void print_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);

int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i++)
		do_cmd(argv[i]);
}

static void do_cmd(char *cmd)
{
	struct tms tmsstart, tmsend;
	clock_t start, end;
	int status;
	fprintf(stderr,"Command: %s\n", cmd);
	if ((start = times(&tmsstart)) == -1)
		err_sys("Times start error");
	if (( status = system(cmd)) < 0)
		err_sys("System error");
	if ((end = times(&tmsend)) == -1)
		err_sys("Times end error");
	print_times(end - start, &tmsstart, &tmsend);
	print_exit(status);
}

static void print_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
	static long tclock = 0;
	if (tclock == 0)
		if ((tclock = sysconf(_SC_CLK_TCK)) < 0)
			err_sys("Sysconf error");
	fprintf(stderr," real:\t%7.2f\n",real/(double)tclock);
	fprintf(stderr," user:\t%7.2f\n", (tmsend->tms_utime - tmsstart->tms_utime)/(double) tclock);
	fprintf(stderr," sys:\t%7.f\n", (tmsend->tms_stime - tmsstart->tms_stime)/(double) tclock);
	fprintf(stderr," child user:\t%7.2f\n",(tmsend->tms_cutime - tmsstart->tms_cutime)/(double) tclock);
	fprintf(stderr," child sys:\t%7.2f\n", (tmsend->tms_cstime - tmsstart->tms_cstime)/(double) tclock);
}
