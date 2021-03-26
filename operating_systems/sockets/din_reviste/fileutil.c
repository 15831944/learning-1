/*
 * fileutil.c
 * From Atelier PC by Eugen Rotaru
 *  Created on: Mar 26, 2021
 *      Author: Gabriel Dimitriu
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include "openfile.h"

int sendfile(int dsoclu, int fd)
{
	struct iovec iov[1];
	struct msghdr msg;
	iov[0].iov_base = (char *)0;
	iov[0].iov_len = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	msg.msg_name = (caddr_t)0;
	msg.msg_control = (caddr_t)&fd;
	msg.msg_controllen = sizeof(fd);
	if (sendmsg(dsoclu, &msg, 0) < 0)
		return (errno > 0) ? errno : 255;
	return 0;
}

int recvfile(int dsoclu)
{
	int fd;
	struct iovec iov[1];
	struct msghdr msg;
	iov[0].iov_base = (char *)0;
	iov[0].iov_len = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	msg.msg_name = (caddr_t) 0;
	msg.msg_control = (caddr_t)&fd;
	msg.msg_controllen = sizeof(fd);
	if (recvmsg(dsoclu, &msg,0) < 0)
		return -1;
	return fd;
}
