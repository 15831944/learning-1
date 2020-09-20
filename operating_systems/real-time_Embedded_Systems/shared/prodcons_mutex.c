/*
 * prodcons_mutex.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int shared_buffer = -1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
		firstget = get_shared_buffer();
		sleep(1);
		secondget = get_shared_buffer2();
		sum +=secondget;
		fprintf(stdout,"Consumer process\t\t\t\t%2d.%2d.%2d\n", firstget, secondget, sum);
		pthread_mutex_unlock(&mutex);
	}
	fprintf(stdout,"\n%s %d\n%s\n", "Consumer read values total", sum, "Terminating consumer");
}

void *producer(void *notused) {
	int sum = 0;
	int r, count;
	for (count = 1; count <= 10; count++) {
		r = rand() % 4;
		sleep(r);
		pthread_mutex_lock(&mutex);
		set_shared_buffer(count);
		sum += count;
		fprintf(stdout,"\t%2d\n", sum);
		pthread_mutex_unlock(&mutex);
	}
	fprintf(stdout,"Producer done\nTerminating Producer\n");
}

int main() {
	fprintf(stdout, "Action\t\tValue\tSum of Produced\tfirst.second.sum\n");
	fprintf(stdout, "------\t\t-----\t---------------\t----------------\n");

	pthread_attr_t attr;
	struct sched_param sp;
	pthread_t cons;
	pthread_t prod;

	pthread_attr_init(&attr);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

	sp.sched_priority = 30;
	pthread_attr_setschedparam(&attr, &sp);

	pthread_create(&prod, &attr, producer, NULL);

	sp.sched_priority = 20;
	pthread_attr_setschedparam(&attr, &sp);

	pthread_create(&cons, &attr, consumer, NULL);
	sleep(30);
	return 1;
}
