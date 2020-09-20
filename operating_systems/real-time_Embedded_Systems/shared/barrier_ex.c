/*
 * barrier_ex.c
 *
 *  Created on: Sep 17, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define THREAD_PLAYER 4

typedef struct {
	pthread_mutex_t barrier_lock;
	pthread_cond_t barrier_condvar;
	int barrier_count;
	int barrier_threshold;
} barrier_t;

barrier_t *barrier;

char msg[] = "   0  \t\t_______________________\t_______________________\t_______________________\t_______________________\n";
int msgindex[] = {20, 43, 67, 91};
char zero = '0';
int step = 0;

void print_msg(int index) {
	int myid = pthread_self();
	step++;
	msg[3] = zero + (step % 10);
	msg[msgindex[index]] = '!';
	fprintf(stdout,"\n");
	fprintf(stdout, "%s",msg);
}

barrier_t *initialize_barrier(int threshold) {
	barrier_t *mybarrier = (barrier_t *)malloc(sizeof(barrier_t));

	pthread_mutex_init(&mybarrier->barrier_lock, NULL);
	pthread_cond_init(&mybarrier->barrier_condvar, NULL);
	mybarrier->barrier_count = 0;
	mybarrier->barrier_threshold = threshold;
	return mybarrier;
}

void barrier_sync_point(barrier_t *lbarrier, int index) {
	pthread_mutex_lock(&lbarrier->barrier_lock);
	print_msg(index);
	lbarrier->barrier_count++;
	if (lbarrier->barrier_count < lbarrier->barrier_threshold) {
		pthread_cond_wait(&lbarrier->barrier_condvar, &lbarrier->barrier_lock);
	} else {
		fprintf(stdout,"\nEnough threads passed the barrier\n");
		lbarrier -> barrier_count = 0;
		int i;
		for (i = lbarrier->barrier_threshold; i > 0; i--)
			pthread_cond_signal(&lbarrier->barrier_condvar);
	}
	pthread_mutex_unlock(&lbarrier->barrier_lock);
}

void *usertask(void *index) {
	int ind = *((int *)index);
	int r = rand() % 5;
	sleep(r + 1);
	barrier_sync_point(barrier, ind);
	sleep(r);
	fprintf(stdout,"Thread %ld is done !\n",pthread_self());
}

int main() {
	pthread_t thread[THREAD_PLAYER];
	int indexes[THREAD_PLAYER];
	barrier = initialize_barrier(THREAD_PLAYER);
	pthread_attr_t attr;
	struct sched_param sp;

	pthread_attr_init(&attr);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

	sp.sched_priority = 30;
	pthread_attr_setschedparam(&attr, &sp);

	int i;
	for (i = 0; i < THREAD_PLAYER; i++) {
		indexes[i] = i;
		pthread_create(&thread[i], &attr, usertask, &indexes[i]);
	}
	fprintf(stdout,"Step\t\tThread %ld\tThread %ld\tThread %ld\tThread %ld\n",thread[0],thread[1],thread[2],thread[3]);
	fprintf(stdout, "%s", msg);
	sleep(20);
	return 1;
}
