/*
 * client_req.c
 * to run with: client_req <nr> [[;client_req <nr> ...] | [& c <nr>]]
 *  Created on: Sep 9, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */


#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "packet.h"
#include "../../common/hdr.h"

int datapipe, ctrlpipe, Ok;

void handler(int sem)
{
	signal(SIGUSR1, handler);
	Ok++;
}

int connect()
{
	struct packet pk;
	ctrlpipe = open(CNAME, O_WRONLY | O_NDELAY);
	datapipe = open(DNAME, O_RDONLY | O_NDELAY);
	if (datapipe < 0)
		err_sys("Could not open datapipe");
	if (ctrlpipe < 0)
		err_sys("Coudl not open ctrlpipe");
	pk.pk_pid = getpid();
	pk.pk_code = CONNECT;

	Ok = 0;
	write(ctrlpipe, &pk, sizeof(pk));
	while(!Ok);
	read(datapipe, &pk, sizeof(pk));
	kill (pk.pk_pid, SIGUSR1);
	return(pk.pk_pid);
}

int request(char *ptr, int blk, int spid)
{
	struct packet pk;
	int no;
	pk.pk_pid = getpid();
	pk.pk_blk = blk;
	pk.pk_code = READ;

	Ok = 0;
	write(ctrlpipe, &pk, sizeof(pk));
	while(!Ok);

	no = read(datapipe, ptr, DBUF);

	kill(spid, SIGUSR1);
	return no;
}

int main(int argc, char *argv[])
{
	int spid;
	int blk;
	char buffer[DBUF];
	int no;

	blk = atoi(argv[1]);
	signal(SIGUSR1, handler);
	spid = connect();
	no = request(buffer, blk, spid);
	write(1, buffer, DBUF);
	printf("\n");
}
