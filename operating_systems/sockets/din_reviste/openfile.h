/*
 * openfile.h
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 26, 2021
 *      Author: Gabriel Dimitriu
 */

#ifndef DIN_REVISTE_OPENFILE_H_
#define DIN_REVISTE_OPENFILE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>

int sendfile(int dsoclu, int fd);
int recvfile(int dsoclu);

#endif /* DIN_REVISTE_OPENFILE_H_ */
