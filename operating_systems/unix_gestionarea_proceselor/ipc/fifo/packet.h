/*
 * packet.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Gabriel Dimitriu
 *  examples from:UNIX - Gestionarea Proceselor by Iosif Ignat and Adrian Kacso
 */

#ifndef IPC_FIFO_PACKET_H_
#define IPC_FIFO_PACKET_H_

#define READ 0 		//request for read form file
#define CONNECT 1	//request to connect to server
#define SENDPIP 2	//send pid

#define DBUF 128

#define DNAME "/tmp/datapipe" //FIFO for data and answers
#define CNAME "/tmp/ctrlpipe" //FIFO control and requests

struct packet {
	int pk_pid;
	int pk_blk;
	int pk_code;
};

#endif /* IPC_FIFO_PACKET_H_ */
