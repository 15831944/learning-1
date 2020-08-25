/*
 * pthread_cleanup.c
 *
 *  Created on: Aug 9, 2020
 *      Author: Gabriel Dimitriu
 */

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void cleanup(void *data) {
	printf("Cleanup in thead %d\n",*((int *)data));
	fflush(stdout);
}

void *executor(void *data)
{
	pthread_cleanup_push(cleanup,data);
	printf("In thread %d\n",*(int *)data);
	fflush(stdout);
	pthread_exit(NULL);
	printf("After exit %d\n",*(int *)data);
	fflush(stdout);
	pthread_cleanup_pop(1);
}

void prepareCall(void)
{
	printf("Called in prepare in pid = %d\n",getpid());
	fflush(stdout);
}

void parentCall(void)
{
	printf("Called in parent in pid = %d\n", getpid());
	fflush(stdout);
}

void childCall(void)
{
	printf("Called in child in pid = %d\n", getpid());
	fflush(stdout);
}

void main() {
	pid_t pid, ppid;
	ppid = getpid();
	pthread_t th1,th2;
	int id1,id2;
	printf("Parent pid = %d\n",ppid);
	fflush(stdout);
	pthread_atfork(prepareCall,parentCall,childCall);
	id1 = 10;
	pthread_create(&th1, NULL,executor,&id1);
	id2 = 11;
	pthread_create(&th2, NULL,executor,&id2);
	pid = fork();
	if (pid == 0)
	{
		printf("Child %d\n", getpid());
		fflush(stdout);
	}
	pthread_join(th1,NULL);
	pthread_join(th2, NULL);
}
