/*
 * child_demo2.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Gabriel Dimitriu
 *   examples from Linux Programming Uleashed by Kurt Wall,
 *	 Mark Watson and Mark Whitis
 */


#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <limits.h>
#include "child.h"

int debug = 1;

int listen_sock;

void child_process_1(child_info_t *child_p, void *private_p) {
	int rc;
	int sleep_time;
	int connection;
	struct sockaddr_in remote_addr;
	int addr_size;
	struct hostent *remote_host;
	char buf[1024];
	char *p;
	int request_remaining = 10;
	int read_fd;
	int write_fd;
	FILE *in;
	FILE *out;
	char s[128];

	assert(child_p);
	request_remaining = 10;

	/* undo signal settings from parent */
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);

	/* this is the child process */
	fprintf(stderr,"Child process #%d starting pid = %d, parent = %d\n", child_p-> number, child_p->pid, child_p->ppid);
	while(request_remaining--) {
		addr_size = sizeof(remote_addr);
		connection = accept(listen_sock, (struct sockaddr *)&remote_addr,&addr_size);
		fprintf(stderr,"accepted connection\n");
		remote_host = gethostbyaddr((void *)&remote_addr.sin_addr, addr_size, AF_INET);
		/* we never bother to free the remote_host settings */
		/* return values from DNS can be hostile */
		if (remote_host) {
			assert(strlen(remote_host->h_name) < 128);
//			assert(remote_host->h_length == 4); /* no IPV6 */
			if (debug) {
				fprintf(stderr, "from: %s\n", remote_host -> h_name);
			}
			strncpy(s,remote_host -> h_name, sizeof(s));
		} else {
			if (debug) {
				fprintf(stderr,"from: [%s]\n", inet_ntoa(remote_addr.sin_addr));
			}
			strncpy(s,inet_ntoa(remote_addr.sin_addr), sizeof(s));
		}
		read_fd = dup(connection);
		write_fd = dup(connection);

		assert(read_fd >= 0);
		assert(write_fd >= 0);

		in = fdopen(read_fd, "r");
		out = fdopen(write_fd, "w");

		assert(in);
		assert(out);

		/* do some work */
		while(1) {
			buf[0] = 0;
			p = fgets(buf, sizeof(buf), in);
			if(!p) break; /* connection probably died */
			buf[sizeof(buf) - 1] = 0;
			p= strrchr(buf,'\n');
			if (p) *p = 0; /* zap newline */
			p = strrchr(buf,'\n');
			if (p) *p = 0; /* zap return */
			fprintf(stderr,"buf=<%s>\n", buf);
			p = strchr(buf,':');
			if (p) {
				/* we never actually get here because we start spewing out a response as soon
				 * as we rx GET, probably an http header which will be ignored
				 */
			} else if(strstr(buf,"GET")) {
				fprintf(stderr,"GET\n");
				fprintf(out,"HTTP/1.0 200 OK");
				fprintf(out,"Content-type: text/html\n");
				fprintf(out,"\n");
				fprintf(out,"<HTML>\n");
				fprintf(out," <HEAD>\n");
				fprintf(out,"   <TITLE>\n");
				fprintf(out,"   Status Page\n");
				fprintf(out,"   </TITLE>\n");
				fprintf(out," </HEAD>\n");
				fprintf(out," <BODY>\n");
				fprintf(out,"   <H1>\n");
				fprintf(out,"   Status Page\n");
				fprintf(out,"   </H1>\n");
				fprintf(out,"   <BR>number=%d\n", child_p->number);
				fprintf(out,"   <BR>pid=%d\n", child_p->pid);
				fprintf(out,"   <BR>ppid=%d\n",child_p->ppid);
				fprintf(out,"   <BR> request remaining=%d\n", request_remaining);
				fprintf(out," </BODY>\n");
				fprintf(out,"</HTML>\n");
				break;
			} else {
				/* something else to do */
			}
		}
		fprintf(stderr,"closing conneciton\n");
		fclose(in);
		fclose(out);
		close(read_fd);
		close(write_fd);
		close(connection);
	}
	fprintf(stderr,"Child process #%d exiting, pid = %d,parent = %d\n", child_p->number, child_p->pid, child_p->ppid);
}

child_group_info_t child_group_1;
jmp_buf jump_env;

void sig_handler(int signal) {
	fprintf(stderr, "pid %d received signal %d\n", getpid(), signal);
	child_restart_children = 0;
#if 0
	/* wake up the wait() doesn't work */
	raise(SIGCHLD);
#endif
	longjmp(jump_env,1);
}

int port = 1236;

void main() {
	int i;
	int child;
	child_group_info_t child_group_1;
	child_groups_t child_groups;
	int rc;
	struct sockaddr_in tcpaddr;
	tcpaddr.sin_family = AF_INET;
	tcpaddr.sin_addr.s_addr = INADDR_ANY;
	tcpaddr.sin_port = htons(port);
	listen_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	if (listen_sock >= 0) perror("socket");
	assert(listen_sock >= 0);

	fprintf(stderr,"listening on port %d\n", port);
#if 1
	rc = bind(listen_sock, (struct sockaddr *)&tcpaddr, sizeof(tcpaddr));
#else
	rc = bind(listen_sock, (struct sockaddr *)&tcpaddr, 4);
#endif
	if (rc != 0) perror("bind");
	assert(rc  == 0);
	rc = listen(listen_sock, 10);
	if (rc != 0) perror(listen);
	assert(rc == 0);

#if 0
	setvbuf(stderr, NULL, _IOLBF, 0);
#else
	setbuf(stderr, NULL);
#endif

	/* children inherit this */
	signal(SIGTERM, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);

	child_group_create(&child_group_1, 4, 4, child_process_1, NULL);

	child_groups.ngroups = 1;
	child_groups.group[0] = &child_group_1;

	rc = setjmp(jump_env);
	if (rc == 0) {
		/* normal execution */
		child_groups_keepalive(&child_groups);
	} else {
		/* exception handler get by setjmp() */
		/* restore signal handlers to default */
		signal(SIGTERM, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		child_groups_kill(&child_groups);
		exit(0);
	}
}
