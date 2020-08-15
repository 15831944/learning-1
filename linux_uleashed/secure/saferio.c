/*
 * saferio.c
 * strange but it give: Opening file: Bad address
 *  Created on: Aug 15, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */
/* Copyright 1999 by Mark Whitis. All rights reserved. */
/* See the following URL for license terms: */
/* http://www.freelabs.com/~whitis/software/license.html */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>

int debug = 6;
/*
 * these functiones have the unpleasant side effect of changing the working
 * directory (although they try to restore it).
 * this can be bad if you  need re-entrant code.
 * Also, be careful in signal handlers - you might find yourself in a
 * very unfriendly place.
 * Strange things might also happen on strange remote filesystem which
 * do not obey UN*X semantics
 */

int one_chdir_step(char *name)
{
	int fd;
	int rc;
	struct stat lstats;
	struct stat fstats;

	if (debug >= 5) {
		fprintf(stderr,"one_chdir_step(): attempting to chdir to %s\n", name);
	}
	rc = lstat(name,&lstats);
	if (rc<0) {
		if(debug)
			perror("one_chdir_step(): lstat()");
		return(-1);
	}
#if 0
	if(lstats.st_nlink > 1) {
		/* hard link detected, this might be legit but we are paranoid */
		if(debug) {
			fprintf(stderr,"one_chdir_step(): lstats.st_nlink=%d\n", lstats.st_nlink);
		}
		errno = EXDEV;
		return(-1);
	}
#endif
	/* this will fail if directory is execute only */
	fd = open(name, O_RDONLY, 0);
	if (fd < 0) {
		if(debug)
			perror("one_chdir_step(): open()");
		return(-1);
	}
	rc = fchdir(fd);
	if(rc<0) {
		if(debug)
			perror("one_chdir_step(): fchdir()");
		close(fd);
		return(-1);
	}
	rc = fstat(fd,&fstats);
	if(rc<0) {
		if(debug)
			perror("one_chdir_step(): fstat()");
		close(fd);
		return(-1);
	}
	/* perhaps we should check other  fields */
	if((fstats.st_dev != lstats.st_dev) || (fstats.st_ino != lstats.st_ino)) {
		/* we have probably traversed a symbolic link or the directory was changed */
		if(debug) {
			fprintf(stderr,"one_chdir_step(): stat compararison failed\n");
		}
		close(fd);
		return (-1);
	}
	if(debug >=5) {
		fprintf(stderr,"one_chdir_step(): successful\n");
	}
	close(fd);
	return(0);
}

int safer_chdir(char *pathname)
{
	char pathtokens[PATH_MAX];
	char *current;
	int saved_cwd;
	int saved_errno;
	int rc;
	saved_cwd = open(".", O_RDONLY, 0);
	if(saved_cwd < 0) {
		if(debug)
			perror("safer_chdir(): could not open current dir");
		return(-1);
	}
	strncpy(pathtokens, pathname, sizeof(pathtokens));
	pathtokens[sizeof(pathtokens)-1] = 0;
	if(pathname[0] == '/') {
		/*leading delimiter confuse strtok() */
		one_chdir_step("/");
	}
	/* not reentrant */
	current = strtok(pathtokens,"/");
	while(current) {
		rc = one_chdir_step(current);
		if(rc < 0) {
			/* restore current directory */
			saved_errno = errno;
			fchdir(saved_cwd);
			close(saved_cwd);
			errno = saved_errno;
			return(-1);
		}
		current = strtok(NULL,"/");
	}
	close(saved_cwd);
	return (0);
}


int safer_open(const char *pathname, int flags, mode_t mode)
{
	char pathtokens[PATH_MAX];
	char *p;
	char *prefix;
	char *basename;
	int saved_cwd;
	int saved_errno;
	int fd;
	int rc;
	if(flags & O_CREAT) {
		/*we cannot safely create a file, use rename */
		if(debug) {
			fprintf(stderr, "safer_open(): O_CREAT is risky\n");
		}
	}
	saved_cwd = open(".", O_RDONLY,0);
	if(saved_cwd < 0) {
		if(debug)
			perror("safer_open(); could not open current dir");
		return(-1);
	}
	strncpy(pathtokens, pathname, sizeof(pathtokens));
	pathtokens[sizeof(pathtokens)- 1] = 0;
	p = strrchr(pathtokens,'/');
	if(p) {
		*p = 0;
		prefix = &pathtokens[0];
		basename = p + 1;
	} else {
		prefix = "";
		basename = &pathtokens[0];
	}
	if(*prefix) {
		rc = safer_chdir(prefix);
		if(rc < 0) {
			if (debug)
				perror("safer_open(): could not safer_chdir()");
			saved_errno = errno;
			fchdir(saved_cwd);
			close(saved_cwd);
			errno = saved_errno;
			return (-1);
		}
	}
	fd = open(basename, flags, mode);
	if(fd < 0) {
		if(debug)
			perror("safer_open(): could not open()");
		saved_errno = errno;
		fchdir(saved_cwd);
		close(saved_cwd);
		errno = saved_errno;
		return(-1);
	}
	fchdir(saved_cwd);
	close(saved_cwd);
	return(fd);
}

/*
 * It is still not a good idea to create a file with safer_fopen() unless
 * it is in a directory no one else has write access to.
 * The trick here is we use safer_open() and fdopen() to replace fopen()
 */

FILE *safer_fopen(const char *path, const char *mode)
{
	int open_flags;
	int append;
	int fd;
	off_t offset;
	int saved_errno;
	FILE *file;
	append = 0;
	if(strcmp(mode,"r") == 0) {
		open_flags = O_RDONLY;
	} else if(strcmp(mode,"r+") == 0) {
		open_flags = O_RDWR;
	} else if(strcmp(mode, "w") == 0) {
		open_flags = O_WRONLY;
	} else if (strcmp(mode, "w+") == 0) {
		open_flags = O_RDWR | O_CREAT;
	} else if (strcmp(mode,"a") == 0) {
		open_flags = O_WRONLY;
		append = 1;
	} else if (strcmp(mode, "a+") == 0) {
		open_flags = O_RDWR | O_CREAT;
		append = 1;
	} else {
		errno  = EINVAL;
		return(NULL);
	}
	fd = safer_open(path, open_flags, 0666);
	if(fd < 0)
		return NULL;
	if(append)
		offset = lseek(fd, 0, SEEK_END);
	if(offset == (off_t) -1) {
		saved_errno = errno;
		close(fd);
		errno = saved_errno;
		return NULL;
	}
	file = fopen(fd, mode);
	if(!file) {
		saved_errno = errno;
		close(fd);
		errno = saved_errno;
		return NULL;
	}
	if(debug >= 5)
		fprintf(stderr, "safer_fopen(): open successful\n");
	return file;
}

int safer_fclose(FILE *stream)
{
	int fd;
	fd = fileno(stream);
	fclose(stream);
	close(fd);
}

int main(int argc, char *argv[])
{
	int i;
	char buf[4096];
	int fd;
	FILE *file;
	int rc;
	/*
	 * these to tests depend on printing out the CWD below
	 * you cannot affect parent process CWD
	 */
#if 0
	for(i = 1; i < argc; i++) {
		one_chdir_step(argv[i]);
	}

	assert(argc ==2);
	safer_chdir(argv[1]);

	assert(argc==2);
	fd = safer_open(argv[1], O_RDONLY, 0);
	if(fd < 0) {
		perror("error opening file");
		exit(1);
	} else {
		printf("open succesful\n");
	}
	rc = read(fd, buf, sizeof(buf));
	if(debug >= 5)
		printf("rc=%d\n", rc);
	close(fd);
#endif

#if 1
	assert(argc == 2);
	file = safer_fopen(argv[1],"r");
	if(!file){
		perror("Opening file");
		exit(1);
	}
	buf[0] = 0;
	while(fgets(buf,sizeof(buf), file)) {
		buf [sizeof(buf)-1] = 0;
		fputs(buf,stdout);
	}
	safer_fclose(file);
#endif
	getcwd(buf, sizeof(buf));
	printf("CWD=%s\n", buf);
}

