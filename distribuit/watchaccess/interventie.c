/*
 * interventie.c
 * Interventie server
 *  Created on: Jul 14, 2020
 *      Author: Gabriel Dimitriu
 * Examples from Programarea distribuita in internet metode si aplicatii
 * by Florian Mircea Boian Editura Albastra 1999
 */

#include "watchaccess.h"

/* shell script to send emails */
#define SH_MAILV " mail -s \"Proces vechi\" "
#define PROCES_VECHI "<<XXXXXXX\n Opriti procesul Nr: "
#define COADA_PROCES " deoarece este prea vechi. Multumim.\n XXXXXXX\n"

#define SH_MAILF "mail -f \"Fara angajament\" "
#define COADA_FARA "<<XXXXXXX\n Rugam completati un angajanment, altfel vi se blocheaza contul. \
	Multumim.\n XXXXXXX\n"

int main(int argc, char *argv[])
{
	Mesaj *Cerere, *Raspuns, *Initializare;
	struct sockaddr_in Interventie, Supraveghere;

	char s[MAX], *p, User[MAX], Pid[MAX], d[MAX];
	short l;
	int nv, nf, sd, fd, len_addr;
	FILE *f;
	/* inits */
	if (argc != 3) // validate nr or arguments
		ERR("Interventie", 201);
	gethostname(s, MAX);
	/* create the initializate message */
	Initializare = Alloc(4*sizeof(short) + strlen(argv[2]) + 1);
	AtribuireI(Initializare, 1, 1);
	AtribuireI(Initializare, 2, 1);
	AtribuireI(Initializare, 3, atoi(argv[1]));
	AtribuireS(Initializare, 0, argv[2]);

	/* create the answer request */
	Raspuns = Alloc(4*sizeof(short) + strlen(s) + 1);
	AtribuireI(Raspuns, 1,1);
	AtribuireI(Raspuns, 2, 1);
	AtribuireI(Raspuns, 3, getuid());
	AtribuireS(Raspuns, 0, s);

	/* create socket address */
	memset((char *)&Supraveghere, 0, sizeof(Supraveghere));
	memset((char *)&Interventie, 0, sizeof(Interventie));
	Interventie.sin_family = AF_INET;
	Interventie.sin_addr.s_addr = htonl(INADDR_ANY);
	Interventie.sin_port = htons(PORT_INTERVENTIE);

	/* init socket connection */
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR("Interventie", 202);
	if(bind(sd,(struct sockaddr *)&Interventie, sizeof(Interventie)) != 0)
		ERR("Interventie", 203);
	if (listen(sd, 5) != 0)
		ERR("Interventie", 204);
	signal(SIGCHLD, SIG_IGN); //prevent zombie
	/* server main loop*/
	for(;;) {
		if ((fd = accept(sd,(struct sockaddr *)&Supraveghere, &len_addr)) < 0)
			ERR("Interventie", 205);
		f = popen("date","r");
		fgets(User, MAX, f);
		fclose(f);
		User[strlen(User)-1] = 0; // prepare date and hour
		sprintf(d,"I: %s",User);
		/* receive request message */
		if (Recv(fd, (char *)&l, sizeof(short)) < 0) {
			MES(d, 206);
			continue;
		}
		l = htons(l);
		Cerere = Alloc(l);
		if (Recv(fd, (char *)Cerere + sizeof(short),l - sizeof(short)) < 0) {
			MES(d, 207);
			continue;
		}
		/* validate the content of received message */
		if (!Valid(Cerere) ||
				(ValoareI(Cerere, 1) != 3) ||
				(ValoareI(Cerere, 2) != 3) ||
				(ValoareI(Cerere, 3) != ValoareI(Initializare, 3)) ||
				(strstr(ValoareS(Initializare, 0), ValoareS(Cerere, 0))) == 0) {
			MES(d, 208);
			continue;
		}
		/* write information into local files */
		nv = ValoareI(Cerere, 4);
		nf = ValoareI(Cerere, 5);
		f = fopen("PROCESE_VECHI", "w");
		fprintf(f,"%s", ValoareS(Cerere, 1));
		fclose(f);

		/*prepare and send messages to the culprits */
		p = (char *)Cerere + 6 * sizeof(short) + strlen(ValoareS(Cerere,0)) + 1;
		for(l = 0; l < nv; l++) {
			strncpy(User,p,(char *)index(p,'\t') - p);
			User[(char *)index(p,'\t') - p] = '\0';
			p += strlen(User) + 1;
			strncpy(Pid, p, (char *)index(p,'\n') - p);
			Pid[(char *)index(p,'\n') - p] = '\0';
			p += strlen(Pid) + 1;
			sprintf(s, "%s %s %s %s %s", SH_MAILV, User, PROCES_VECHI, Pid, COADA_PROCES);
			f = fopen(s,"t"); // message to the user with old process
			fclose(f);
		}
		p++;
		for(l = 0; l < nf; l++) {
			strncpy(User,p,(char *)index(p,'\n') - p);
			User[(char *)index(p,'\n') - p] = '\0';
			p += strlen(User) + 1;
			sprintf(s, "%s %s %s", SH_MAILF, User, COADA_FARA);
			f = popen(s, "r"); //message the the user without agreement
			fclose(f);
		}
		Delete(Cerere);
		/* confirm the intervention and close */
		if (Send(fd, (char *)Raspuns, ValoareI(Raspuns, 0)) < 0)
			ERR(d, 209);
		close(fd);
	}
}
