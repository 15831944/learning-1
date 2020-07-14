/*
 * supraveghere.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "watchaccess.h"
#include <sys/wait.h>

#define SH_SUPRAVEGHERE "sh shS.sh "
extern time_t time();

int main(int argc, char *argv[]) {
	Mesaj *CerereConst, *CerereInterv, *RaspunsConst, *RaspunsInterv,
			*Initializare;
	struct sockaddr_in Constatare, Interventie;
	struct hostent *hp;
	char s[MAX], d[MAX], *p;
	int n, l, i, sdc, sdi, lv, cv, lf, cf;
	FILE *f;

	/* inits */
	if ((argc < 6) || argc % 3 != 0)
		ERR("Supraveghere", 301);
	n = argc / 3 - 1;
	for (i = 3 + 2 * n, l = 0; i < argc; i++)
		l += strlen(argv[i]) + 1;
	/* init the initialization message */
	Initializare = Alloc((2 * n + 5) * sizeof(short) + 1);
	AtribuireI(Initializare, 1, 2 * n + 2);
	AtribuireI(Initializare, 2, n);
	AtribuireI(Initializare, 3, atoi(argv[1]));
	AtribuireI(Initializare, 4, atoi(argv[2]));
	/* convert and move to Initializare */
	for (i = 0; i < n; i++) {
		AtribuireI(Initializare, 5 + i, atoi(argv[3 + i]));
		AtribuireI(Initializare, 5 + n + i, atoi(argv[3 + n + i]));
		AtribuireS(Initializare, i, argv[3 + 2 * n + i]);
	}
	srand((int) time((long*) 0));
	/* prepare request */
	gethostname(s, MAX);
	CerereConst = Alloc(4 * sizeof(short) + strlen(s) + 1);
	AtribuireI(CerereConst, 1, 1);
	AtribuireI(CerereConst, 2, 1);
	AtribuireI(CerereConst, 3, getuid());
	AtribuireS(CerereConst, 0, s);

	signal(SIGCHLD, SIG_IGN); //prevent zombie
	/* random call between argv[1] and argv[2] seconds */
	/* main loop */
	for (;;
			sleep(
					ValoareI(Initializare, 3)
							+ rand()
									% (ValoareI(Initializare, 4)
											- ValoareI(Initializare, 3)))) {
		/* for each server */
		for (i = 0; i < n; i++) {
			if (fork() == 0) {
				f = popen("date", "r");
				fgets(s, MAX, f);
				fclose(f);
				s[strlen(s) - 1] = 0; //prepare machine date, hour
				/* get the IP of the server */
				if ((hp = gethostbyname(ValoareS(Initializare, i))) == NULL)
					ERR(d, 302);
				/* prepare the sockets */
				memset((char*) &Interventie, 0, sizeof(Interventie));
				memset((char*) &Constatare, 0, sizeof(Constatare));
				Constatare.sin_family = AF_INET;
				Interventie.sin_family = AF_INET;
				bcopy(hp->h_addr, (char *)&Constatare.sin_addr.s_addr, hp -> h_length);
				bcopy(hp->h_addr, (char *)&Interventie.sin_addr.s_addr, hp -> h_length);
				Constatare.sin_port = htons(PORT_CONSTATARE);
				Interventie.sin_port = htons(PORT_INTERVENTIE);
				/* init the communication with the server number i */
				if ((sdc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
					ERR(d, 303);
				if (connect(sdc, (struct sockaddr*) &Constatare,
						sizeof(Constatare)) != 0) {
					MES(d, 304);
					continue;
				}
				/* Constatare request */
				if (Send(sdc, (char*) CerereConst, ValoareI(CerereConst, 0))
						< 0)
					ERR(d, 305);
				/* read the answer */
				if (Recv(sdc, (char*) &l, sizeof(short)) < 0) {
					MES(d, 306);
					continue;
				}
				l = htons(l);
				RaspunsConst = Alloc(l);
				if (Recv(sdc, (char*) RaspunsConst + sizeof(short),
						l - sizeof(short)) < 0) {
					MES(d, 307);
					continue;
				}
				/* validate the answer from Constatare */
				if ((!Valid(RaspunsConst) || (ValoareI(RaspunsConst, 1) != 1)
						|| (ValoareI(RaspunsConst, 2) != 4)
						|| (ValoareI(RaspunsConst, 3)
								!= ValoareI(Initializare, 5 + i))
						|| (strstr(ValoareS(Initializare, i),
								ValoareS(RaspunsConst, 0)) == 0))) {
					MES(d, 308);
					continue;
				}
				close(sdc);
				/* process the state and prepare the interventions */
				/* create the file NETSTAT */
				sprintf(s, "%s.NETSTAT", ValoareS(RaspunsConst, 0));
				if ((f = fopen(s, "w")) == NULL)
					ERR(d, 309);
				fprintf(f, "%s", ValoareS(RaspunsConst, 1));
				fclose(f);
				/* create the file WHO */
				sprintf(s, "%s.WHO", ValoareS(RaspunsConst, 0));
				if ((f = fopen(s, "w")) == NULL)
					ERR(d, 310);
				fprintf(f, "%s", ValoareS(RaspunsConst, 2));
				fclose(f);
				/* create the file PS */
				sprintf(s, "%s.PS", ValoareS(RaspunsConst, 0));
				if ((f = fopen(s, "w")) == NULL)
					ERR(d, 311);
				fprintf(f, "%s", ValoareS(RaspunsConst, 3));
				fclose(f);
				/* process for interventie */
				/* extract the users */
				sprintf(s,"%s %s", SH_SUPRAVEGHERE, ValoareS(RaspunsConst, 0));
				Delete(RaspunsConst);
				f = fopen(s, "r");
				fscanf(f,"%d\n%d\n%d\n%d\n", &lv,&cv,&lf,&cf);
				/* create the intervention request */
				l = 6*sizeof(short)+strlen(ValoareS(CerereConst,0)) + 1;
				CerereInterv = Alloc(l + cv+cf+2);
				AtribuireI(CerereInterv, 1, 3);
				AtribuireI(CerereInterv, 2, 3);
				AtribuireI(CerereInterv, 3, ValoareI(CerereConst, 3));
				AtribuireI(CerereInterv, 4, lv);
				AtribuireI(CerereInterv, 5, lf);
				AtribuireS(CerereInterv, 0, ValoareS(CerereConst, 0));

				p = (char *)CerereInterv + 1;
				/* write into the message the users with old processes*/
				for (l = 0; l < cv; l++, p++)
					(*p) = fgetc(f);
				(*p) = 0;
				/* write into the message the users without angajamente */
				for(l = 0; l < cf; l++, p++)
					(*p) = fgetc(f);
				(*p) = 0;
				fclose(f);
				/* open the intervention connection */
				if ((sdi = socket(AF_INET, SOCK_STREAM, 0)) < 0)
					ERR(d, 312);
				if(connect(sdi, (struct sockaddr *)&Interventie, sizeof(Interventie)) != 0) {
					MES(d, 313);
					continue;
				}
				/* send the intervention messages */
				if (Send(sdi, (char *)CerereInterv, ValoareI(CerereInterv, 0)) < 0)
					ERR(d, 314);
				/* read the intervention confirmation */
				if (Recv(sdi, (char *)&l,sizeof(short)) < 0) {
					MES(d, 315);
					continue;
				}
				l = htons(l);
				RaspunsInterv = Alloc(l);
				if (Recv(sdi, (char *)RaspunsInterv + sizeof(short), l - sizeof(short)) < 0) {
					MES(d,316);
					continue;
				}
				/* validate the received message */
				if ((!Valid(RaspunsInterv) ||
						(ValoareI(RaspunsInterv, 1) != 1) ||
						(ValoareI(RaspunsInterv, 2) != 1) ||
						(ValoareI(RaspunsInterv, 3) != ValoareI(Initializare, 5+ n +i)) ||
						(strstr(ValoareS(Initializare, i), ValoareS(RaspunsInterv, 0)) == 0)
						)) {
					MES(d, 317);
					continue;
				}
				close(sdi);
				exit(0);
			}
		}
		for(i = 0; i < n; i++)
			wait(0);
	}
}
