/*
 * rwlock.c
 *
 *  Created on: Sep 17, 2020
 *      Author: Gabriel Dimitriu
 *  Examples from : Real-Time Embedded Systems by Xiaocong Fan Publisher Newnes February 2005
 */

//@ a task is started, waiting for mutex
//. a task is waiting for read condition variable
//* a task is waiting for write condition variable
//r a task is reading
//w a task is writing
//! a task is done

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define THREAD_PLAYER 8

typedef struct {
	pthread_mutex_t guard_mutex;
	pthread_cond_t read_condvar;
	pthread_cond_t write_condvar;
	int rw_count;
	int waiting_reader_count;
} rwlock_t;

rwlock_t *rwlock;

char msg[] = "_______________________\t_______________________\t_______________________\t_______________________\t_______________________\t_______________________\t_______________________\t_______________________\n";
int msgindex[] = {12, 37,62,87,113,138,160,188};

void print_msg(char c, int ind) {
	msg[msgindex[ind]] = c;
	fprintf(stdout, "%s", msg);
}

void acquire_write_privilege(rwlock_t *rwlock, int index) {
	pthread_mutex_lock(&rwlock -> guard_mutex);
	while(rwlock -> rw_count != 0) {
		print_msg('*', index);
		pthread_cond_wait(&rwlock -> write_condvar, &rwlock -> guard_mutex);
	}
	rwlock -> rw_count = -1;
	pthread_mutex_unlock(&rwlock -> guard_mutex);

}

void release_write_privilege(rwlock_t *rwlock, int index) {
	pthread_mutex_lock(&rwlock->guard_mutex);
	rwlock -> rw_count = 0;
	int i;
	if (rwlock -> waiting_reader_count) {
		for (i = rwlock -> waiting_reader_count; i > 0; i--)
			pthread_cond_signal(&rwlock-> read_condvar);
	} else
		pthread_cond_signal(&rwlock -> write_condvar);
	print_msg('!', index);
	pthread_mutex_unlock(&rwlock->guard_mutex);
}

void acquire_read_privilege(rwlock_t *rwlock, int index) {
	pthread_mutex_lock(&rwlock -> guard_mutex);
	rwlock -> waiting_reader_count ++;
	while(rwlock -> rw_count < 0) {
		print_msg('.', index);
		pthread_cond_wait(&rwlock->read_condvar, &rwlock->guard_mutex);
	}
	rwlock -> waiting_reader_count --;
	rwlock -> rw_count ++;
	pthread_mutex_unlock(&rwlock->guard_mutex);
}

void release_read_privilege(rwlock_t *rwlock, int index) {
	pthread_mutex_lock(&rwlock->guard_mutex);
	rwlock ->rw_count --;
	if (rwlock ->rw_count == 0)
		pthread_cond_signal(&rwlock -> write_condvar);
	print_msg('!', index);
	pthread_mutex_unlock(&rwlock -> guard_mutex);
}

void *reader(void *index) {
	int id = *((int *)index);
	int r = rand() % 5;
	sleep(r+1);
	print_msg('@', id);
	acquire_read_privilege(rwlock, id);
	print_msg('r', id);
	sleep(r);
	release_read_privilege(rwlock, id);
	print_msg(' ', id);
}

void *writer(void *index) {
	int id = *((int *)index);
	int r = rand() % 5;
	sleep(r + 1);
	print_msg('@', id);
	acquire_write_privilege(rwlock, id);
	print_msg('w', id);
	sleep(r);
	release_write_privilege(rwlock, id);
	print_msg(' ', id);
}

rwlock_t * initialize_rwlock() {
	rwlock_t *mylock = (rwlock_t *)malloc(sizeof(rwlock_t));
	memset(mylock, 0, sizeof(rwlock_t));

	pthread_mutex_init(&mylock -> guard_mutex, NULL);
	pthread_cond_init(&mylock -> read_condvar, NULL);
	pthread_cond_init(&mylock -> write_condvar, NULL);
	mylock -> rw_count = 0;
	mylock -> waiting_reader_count = 0;
	return mylock;
}


int main() {
	pthread_t thread[THREAD_PLAYER];
	rwlock = initialize_rwlock();

	int idthreads[THREAD_PLAYER];
	for (int i = 0; i < THREAD_PLAYER; i++)
		idthreads[i] = i;

	pthread_create(&thread[0], NULL, reader, &idthreads[0]);
	pthread_create(&thread[1], NULL, reader, &idthreads[1]);
	pthread_create(&thread[2], NULL, writer, &idthreads[2]);
	pthread_create(&thread[3], NULL, writer, &idthreads[3]);
	pthread_create(&thread[4], NULL, reader, &idthreads[4]);
	pthread_create(&thread[5], NULL, writer, &idthreads[5]);
	pthread_create(&thread[6], NULL, reader, &idthreads[6]);
	pthread_create(&thread[7], NULL, reader, &idthreads[7]);

	fprintf(stdout," T%ld\t T%ld\t T%ld\t T%ld\t T%ld\t T%ld\t T%ld\t T%ld\n",thread[0],thread[1], thread[2], thread[3], thread[4], thread[5], thread[6], thread[7]);
	fprintf(stdout,"_______________________\t_______________________\t_______________________\t_______________________\t_______________________\t_______________________\t_______________________\t_______________________\n");
	sleep(30);
	return 1;
}
