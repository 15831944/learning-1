/*
 * read_dir.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include <dirent.h>
#include <stdio.h>
/* primeste la intrare numele unui director si intoarce prin acelasi parametru lista fisierlor din el */
int read_dir(char *dir)
{
	DIR *dirp;
	struct dirent *d;
	dirp = opendir(dir);
	dir[0] = '\0';
	if(dirp == NULL)
		return 0;
	while (d = readdir(dirp))
		sprintf(dir, "%s%s\n", dir, d -> d_name);
	closedir(dirp);
	return sizeof(dir);
}

