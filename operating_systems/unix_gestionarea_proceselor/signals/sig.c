/*
 * sig.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include "sig.h"

sigfunc *signal(int sig, sigfunc *func)
{
	struct sigaction act, old_act;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (sig == SIGALRM) {
#ifdef SA_INTERRUPT //SunOS
		act.sa_flags |= SA_RESTART;
#endif
	} else {
#ifdef SA_RESTART //SVR4, 4.3BSD
		act.sa_flags |= SA_RESTART;
#endif
	}
	printf(" S I G A C T I O N \n");
	if (sigaction(sig, &act, &old_act) < 0)
		return SIG_ERR;
	return old_act.sa_handler;
}
