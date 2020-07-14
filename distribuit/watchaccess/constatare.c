/*
 * constatare.c
 * The sever which collect metrics
 *  Created on: Jul 14, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */


#include "watchaccess.h"

/* script to extract data from netstat */
#define NETSTAT "netstat -t |\
	awk \'(($1==\"tcp\") && ($6==\"ESTABLISHED\") && \
	((index($4,\"localhost\")==0) ||\
	(index($5,\"localhost\")==0)))\\\n\
	(if ($7 ==\"\") print \"?\\t\" $4 \"\\t\" $5;\
	else print $7 \"\\t\" $4 \"\\t\" $5;)\'>.n;\
	wc -c <.n; cat .n; rm .n"
/* script to extract data from who */
#define WHO "who |\
	awk \'(if($6==\"\") print $1 \"\\t\"\
	$4 \"\\t\" $5 \"\\t?\";\
	else print $1 \"\\t\" $4 \"\\t\" $5 \"\\t\" $6;)\' >.w;\
	wc -c <.w; cat .w; rm .w"
/* script to extract data from ps */
#define PS "ps -aux |\
	awk \'($1!=\"root\") && ($1!=\"nobody\") && ($1!=\"proxy\") && \
	($1!=\"bin\") && ($1!=\"squid\") && ($1!=\"USER\") && ($1!=\"\")\
	(if(index($9,\":\")==0)\
	print $1 \"\\t\" $2 \"\\t24:00\\t\"\
	$11 \" \" $12 \" \" $13 \" \" $14 \" \" $15;\
	else print $1 \"\\t\" $2 \"\\t\" $9 \"\\t\"\
	$11 \" \" $12 \" \" $13 \" \" $14 \" \" $15;)\'>.p;\
	wc -c <.p; cat .p; rm .p"

int main(int argc, char *argv[])
{
	Mesaj *Cerere,*Raspuns,*Initializare;
	struct sockaddr_in Constatare, Supraveghere;
	char s[MAX], d[MAX], r[MAX], *p;
	short l;
	int cn, cw, cp, sd, fd, len_addr;
	FILE *fn, *fw, *fp;
	/* inits */
	if(argc != 3) // check the number of arguments
		ERR("Constatare", 101);
	gethostname(s, MAX);
	/* create the init message */
	Initializare = Alloc(4*sizeof(short)*strlen(argv[2])+1);
	AtribuireI(Initializare, 1,1);
	AtribuireI(Initializare, 2, 1);
	AtribuireI(Initializare, 3, atoi(argv[1]));
	AtribuireS(Initializare, 0, argv[2]);

	/* create the socket address */
	memset((char *)&Supraveghere, 0, sizeof(Supraveghere));
	memset((char *)&Constatare, 0, sizeof(Constatare));
	Constatare.sin_family = AF_INET;
	Constatare.sin_addr.s_addr = htonl(INADDR_ANY);
	Constatare.sin_port = htons(PORT_CONSTATARE);
	/* init socket communication */
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR("Constatare", 102);
	if (bind(sd, (struct sockaddr *)&Constatare, sizeof(Constatare)) != 0)
		ERR("Constatare", 103);
	if (listen(sd, 5) != 0)
		ERR("Constare", 104);
	signal(SIGCHLD, SIG_IGN); // to avoid zombie
	/* main server loop */
	for(;;) {
		if ((fd = accept(sd, (struct sockaddr *)&Supraveghere, &len_addr)) < 0)
			ERR("Constatare", 105);
		fn = popen("date", "r");
		fgets(r, MAX, fn);
		fclose(fn);
		r[strlen(r)-1] = 0; // prepare date and hour
		sprintf(d, "C: %s",r);
		/* receive request message */
		if (Recv(fd, (char *)&l, sizeof(short)) < 0) {
			MES(d, 106);
			continue;
		}
		l = ntohs(l);
		Cerere = Alloc(l);
		if(Recv(fd, ((char *)Cerere) + sizeof(short), l - sizeof(short)) < 0) {
			MES(d, 107);
			continue;
		}
		/* validate received message */
		if (!Valid(Cerere) ||
			(ValoareI(Cerere,1) != 1) ||
			(ValoareI(Cerere,2) != 2) ||
			(ValoareI(Cerere,3) != ValoareI(Initializare,3)) ||
			(strstr(ValoareS(Initializare, 0), ValoareS(Cerere, 0)) == 0)) {
			MES(d, 108);
			continue;
		}
		/* take connection information */
		fn = popen(NETSTAT, "r");
		fw = popen(WHO,"r");
		fp = popen(PS, "r");
		fscanf(fn,"%d\n", &cn);
		fscanf(fw,"%d\n",&cw);
		fscanf(fp,"%d\n",&cp);
		/*prepare request message */
		Raspuns = Alloc(4*sizeof(short) + strlen(s) + cn + cw + cp + 4);
		AtribuireI(Raspuns,1,1);
		AtribuireI(Raspuns, 2, 4);
		AtribuireI(Raspuns, 3, getuid());
		AtribuireS(Raspuns, 0, s);
		p = (char *)Raspuns + 4*sizeof(short) + strlen(s) + 1;
		for (l = 0; l < cn; l++, p++)
			(*p) = fgetc(fn); // copy the netstat string
		(*p) = 0;
		p++;
		for( l = 0; l < cw; l++, p++)
			(*p) = fgetc(fw); // copy the who string
		(*p) = 0;
		p++;
		for(l = 0; l < cp; l++, p++)
			(*p) = fgetc(fp); //copy the ps string
		(*p) = 0;
		p++;

		fclose(fn);
		fclose(fw);
		fclose(fp);
		/* send the ack */
		if (Send(fd, (char *)Raspuns, ValoareI(Raspuns,0)) < 0)
			ERR(d, 109);
		Delete(Raspuns);
		close(fd);
	}
}
