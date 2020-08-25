/*
 * badptr.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <assert.h>
#include <stdio.h>
//#define NDEBUG //disable asserts
int main(void) {
	FILE *fp;
	fp =fopen("foo_bar", "w"); /* this should work */
	assert(fp);
	fclose(fp);
	fp = fopen("bar_baz", "r"); /* this should fail */
	assert(fp);
	fclose(fp); /* should never get here */
	return 0;
}
