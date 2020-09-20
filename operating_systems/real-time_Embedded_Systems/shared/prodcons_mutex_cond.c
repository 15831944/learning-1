/*
 * prodcons_mutex_cond.c
 *
 *  Created on: Sep 17, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */


#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int shared_buffer = -1;

int pred_data_ready = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

void set_shared_buffer(int value) {
	fprintf(stdout, "Producer writes\t%2d", value);
	shared_buffer = value;
}

int get_shared_buffer() {
	fprintf(stdout, "Consumer reads\t%2d\n", shared_buffer);
	return shared_buffer;
}

int get_shared_buffer2() {
	return shared_buffer;
}

void *consumer(void *notused) {
	int sum = 0;
	int firstget, secondget;
	int r, count;
	for (count = 1; count <= 10; count++) {
		r = rand() % 4;
		sleep(r);
		pthread_mutex_lock(&mutex);
		while(!pred_data_ready) {
			pthread_cond_wait(&condvar, &mutex);
		}
		firstget = get_shared_buffer();
		sleep(1);
		secondget = get_shared_buffer2();
		sum += secondget;
		fprintf(stdout, "Consumer process\t\t\t%2d.%2d.%2d\n", firstget, secondget, sum);
		pred_data_ready = 0;
		pthread_cond_signal(&condvar);
		pthread_mutex_unlock(&mutex);
	}
	fprintf(stdout,"\n%s %d\n%s\n","Consumer read value total", sum, "Terminating Consumer");
}

void *producer(void *notused) {
	int sum = 0;
	int r, count;
	for(count = 1; count <= 10; count++) {
		r = rand() % 4;
		sleep(r);

		pthread_mutex_lock(&mutex);
		while(pred_data_ready) {
			pthread_cond_wait(&condvar, &mutex);
		}
		set_shared_buffer(count);
		sum += count;
		fprintf(stdout,"\t%2d\n", sum);
		pred_data_ready = 1;
		pthread_cond_signal(&condvar);
		pthread_mutex_unlock(&mutex);
	}
	fprintf(stdout,"Producer done\nTerminating Producer\n");
}

int main() {
	fprintf(stdout,"Action\t\tValue\tSum of Produced\tfirst.second.Sum\n");
	fprintf(stdout,"------\t\t-----\t---------------\t----------------\n");

	pthread_attr_t attr;
	pthread_t pth;
	struct sched_param sp;
	pthread_attr_init(&attr);
	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);

	sp.sched_priority = 30;
	pthread_attr_setschedparam(&attr,&sp);
	pthread_create(&pth, &attr, producer, NULL);

	sp.sched_priority = 20;
	pthread_attr_setschedparam(&attr, &sp);
	pthread_create(&pth,&attr, consumer, NULL);

	sleep(50);
	return 1;
}
