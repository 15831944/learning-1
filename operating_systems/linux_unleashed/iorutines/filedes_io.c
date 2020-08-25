/*
 * filedes_io.c
 *
 *  Created on: Aug 7, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

char sample1[] = "This is sample data 1\n";
char sample2[] = "This is sample data 2\n";
char data[16];

void main()
{
	int fd;
	int rc;
	struct stat statbuf;
	/* create the file */
	printf("Creating file\n");
	fd = open("junk.out",O_WRONLY | O_CREAT | O_TRUNC, 0666);
	assert(fd >= 0);
	rc = write(fd, sample1,strlen(sample1));
	rc = flock(fd, LOCK_EX);
	assert(rc == 0);
	/* sleep so you can try running two copies at one time */
	printf("   sleeping for 10 seconds\n");
	sleep(10);

	printf(" writing data\n");
	rc = write(fd, sample2, strlen(sample2));
	assert(rc == strlen(sample2));

	printf (" unlocking file\n");
	rc = flock(fd, LOCK_UN);
	assert(rc == 0);

	close(fd);

	/* read the file */
	printf("Reading file\n");
	fd = open("junk.out",O_RDONLY);
	assert(fd >= 0);

	while(1) {
		rc = read(fd, data, sizeof(data));
		if (rc > 0) {
			data[rc] = '\0';
			printf("Data read (rc = %d): <%s>\n", rc, data);
		} else if (rc == 0) {
			printf("End of file read\n");
			break;
		} else {
			perror("read error");
			break;
		}
	}
	close(fd);

	/* fiddle with inode */
	printf("Fiddling with inode\n");
	fd = open("junk.out", O_RDONLY);
	assert(fd >= 0);

	printf("changing file mode\n");
	rc = fchmod(fd,0600);
	assert(rc == 0);
	if (getuid() == 0) {
		printf("Changing file owner\n");
		/* if we are root, change file to owner nobody, group nobody */
		rc = fchown(fd, 99, 99);
		assert(rc == 0);
	} else {
		printf("not changing file owner\n");
	}
	fstat(fd, &statbuf);
	printf("file mode=%o (Octal)\n",statbuf.st_mode);
	printf("Owner uid=%d\n",statbuf.st_uid);
	printf("Owner guid=%d\n", statbuf.st_gid);
	close(fd);
}
