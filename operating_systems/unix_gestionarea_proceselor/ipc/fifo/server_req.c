/*
 * server_req.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "packet.h"
#include "../../common/hdr.h"

int datapipe, ctrlpipe, datafile, Ok;

char *dataname = "baza_d.txt";

void handler(int sem)
{
	if (sem == SIGTERM) {
		unlink(DNAME);
		unlink(CNAME);
		printf("Server has been stopped!");
		kill(getpid(),SIGTERM);
	}
	signal(SIGUSR1, handler);
	Ok++;
}

void process(struct packet *pkp, struct packet *spkp)
{
	char pbuf[DBUF];
	int no;

	if ((datapipe = open (DNAME, O_WRONLY | O_NDELAY)) < 0)
		err_sys("Error open datapipe");
	switch(pkp -> pk_code) {
	case CONNECT:
		spkp -> pk_pid = getpid();
		if (write(datapipe, spkp, sizeof(struct packet)) != sizeof(struct packet))
			err_sys("Error write packet");
		printf("Server %d and client %d are connected\n", pkp->pk_pid, spkp->pk_pid);
		break;
	case READ:
		lseek(datafile, pkp->pk_blk*DBUF, 0);
		no = read(datafile, pbuf, DBUF);
		write(datapipe, pbuf, no);
		break;
	default:
		err_quit("Request code unknown!!");
	}
	Ok = 0;
	kill(pkp->pk_pid, SIGUSR1);
	while(!Ok); //wait for receive confirmation
	close(datapipe);
}

void main(void)
{
	struct packet pk, sendpk;
	unlink(DNAME);
	unlink(CNAME);
	if (mkfifo(DNAME, 0666) < 0 || mkfifo(CNAME, 0666) < 0)
		err_sys("Could not create FIFO files !\n");

	ctrlpipe = open(CNAME, O_RDONLY);
	datafile = open(dataname, 0);

	if (ctrlpipe < 0 || datafile < 0)
		err_sys("Could not open ctrl FIFO or data file !");

	sendpk.pk_code = SENDPIP;
	signal(SIGUSR1, handler);
	signal(SIGTERM, handler);
	for(;;)
		while(read(ctrlpipe, &pk, sizeof(pk)))
			process(&pk, &sendpk);
}
