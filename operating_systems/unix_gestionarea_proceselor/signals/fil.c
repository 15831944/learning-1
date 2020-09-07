/*
 * fil.c
 * run with fil & fil & fil & fil & fil
 *  Created on: Sep 3, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "../common/hdr.h"
#include "sig.h"

#define TRUE 1
#define FALSE 0
extern int errno;
static volatile sig_atomic_t ok;
static sigset_t newmask, oldmask, mask;

static void sig_usr(int sig)
{
	ok = 1;
	return;
}

int main()
{
	int fd, coff = 0, noff, poff;
	pid_t pid, cpid, npid, i, n = 5;
	long int dim;
	char path[10], ppath[10];
	int lock(char *);
	void unlock(char *);

	void tell_process(pid_t);
	void wait_process(void);

	for (i = 0; i < n ; i++) {
		path[0] = '\0';
		strcat(path,"/tmp/f0");
		path[strlen(path) - 1] = i + 48;
		if (unlink(path) && errno != ENOENT)
			err_sys("Unlink error");
	}
	path[0] = '\0';
	if ((fd = open("pid_", O_CREAT | O_RDWR | O_APPEND, 0666)) < 0)
		err_sys("Open error");
	pid = getpid();
	//write pid in the shared file
	if (write(fd, &pid, sizeof(pid)) != sizeof(pid))
		err_sys("Write pid error");
	//wait untill all n process are running
	while((dim = lseek(fd, 0L, 2)) != (n*sizeof(pid)));

	//find the current process and the next one
	lseek(fd, 0,0);
	while(read(fd, &cpid, sizeof(pid)) != EOF) {
		if (cpid != pid)
			coff +=1;
		else
			break;
	}
	noff = (coff +1) %n;

	lseek(fd, noff*sizeof(pid), 0);
	read(fd, &npid, sizeof(pid));
	/*
	 * each process use 2 resources: f[coff] and f[poff]
	 * the resources are not existed
	 * each process will create the resources and later on it will delete them
	 * if two process try to create same resource only one will succeed
	 */
	poff = (coff+4) % n;
	strcpy(path,"/tmp/f?");
	path[strlen(path) - 1] = coff + 48;

	strcpy(ppath, "/tmp/f?");
	ppath[strlen(ppath) - 1] = poff + 48;

	unlink("pid_");

	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("Error signal(SIGUSR1,...)");

	sigemptyset(&mask);
	sigemptyset(&newmask);

	sigaddset(&newmask, SIGUSR1);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("Error sigprocmask(SIG_BLOCK,...)");

	//here start the concurency
	for(;;) {
		if (lock(path))
			if (lock(ppath)) {
				printf("Process %d start working\n", coff);
				sleep(10);
				unlock(path);
				unlock(ppath);
				tell_process(npid);
				sleep(3);
				continue;
			}
			else
				unlock(path);
		printf("Process %d waits\n", coff);
		wait_process();
	}
	close(fd);
}

void tell_process(pid_t pid)
{
	kill(pid, SIGUSR1);
}

void wait_process()
{
	while(ok ==0) {
		sigsuspend(&mask);
	}
	ok = 0;
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("Error sigprocmask(SIG_SETMASK, ...)");
}

int lock(char *name)
{
	int fd, incerc = 0;
	while((fd = creat(name, 0) == -1 && errno == EACCES)) {
		if (++incerc >= 5)
			return FALSE;
		sleep(1.9989);
	}
	if(fd == -1 || close(fd) == -1)
		err_sys("Error lock()");
	return TRUE;
}

void unlock(char *name)
{
	if (unlink(name) == -1)
		err_sys("Error unlock()");
}
