/*
 * citeste si afiseaza datele dintr-un fisier de intrare graf.txt
 * acesta contine laturile unui graf: nod initial nod final costul
 * asociat grafului
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define FILENAME "graf.txt"
typedef struct {
	char ni[10];
	char nf[10];
	float cost;
} arc;

/*
 * functia care permite adaugare unei inregistrari si eventual
 * crearea fisierului daca nu exista
 */
void adf(char *nmf)
{
	FILE *fp;
	arc r;
	if (!(fp =fopen(nmf,"at"))) {
		puts("Nu pot deschide fisierul !");
		return;
	}
	printf("Nod initial, final, cost: ");
	scanf("%s%s%f",r.ni,r.nf,&r.cost);
	fflush(stdin);
	fprintf(fp, "%10s%10s%8.2f\n",r.ni,r.nf, r.cost);
	fclose(fp);
}

/*
 * se citeste si se afiseaza fisierul
 */
void lstf(char *nmf)
{
	FILE *fp;
	arc r;
	int i = 1;
	if (!(fp = fopen(nmf,"rt"))) {
		puts("Nu pot deschide fisierul");
		return;
	}
	puts("Nr. Nod initial, Nod final, Cost:");
	while(!feof(fp)) {
		if (feof(fp))
			break;
		fscanf(fp,"%10s%10s%8.2f",r.ni,r.nf,&r.cost);
		printf("%3d %-10s %-10s %8.2f\n", i++, r.ni, r.nf,r.cost);
	}

	fclose(fp);
}

/* cauta o inregistrare pe baza numelui nodului initial
 * si permite modificarea ei la solicitarea operatorului
 */
void afmd(char *nmf)
{
	FILE *fp;
	arc r;
	char nm[15], t;
	long p;
	if (!(fp=fopen(nmf,"r+t"))) {
		puts("Nu pot deschide fisierul");
		return;
	}
	printf("Num ?");
	gets(nm);
	while((t=fscanf(fp, "%10s%10s%5f", r.ni, r.nf,&r.cost)) > 0)
		if(strcmp(nm,r.ni) == 0) {
			/* afiseaza inregistrarea gasita pentru verificare */
			printf("%-10s %-10s %8.2f\n", r.ni, r.nf, r.cost);
			break;
		} else
			printf("%s:",r.ni);
	if (t < 0)
		printf("Nu exista %s in fisier !\n", nm);
	else {
		printf("Modificare ? [y/n]");
		if(tolower(getche()) == 'y') {
			/* pozitionare la inceputul inregistrarii */
			p =ftell(fp) - 30;
			printf("%ld\n", p);fflush(stdout);
			fsetpos(fp, &p);
			printf("\nNod initial, final, cost: ");
			scanf("%s%s%f", r.ni, r.nf, &r.cost);
			fflush(stdin);
			fprintf(fp, "%10s%10s%8.2f\n", r.ni, r.nf,r.cost);
		}
	}
	fclose(fp);
}



void main()
{

	adf(FILENAME);
	adf(FILENAME);
	lstf(FILENAME);
	afmd(FILENAME);
	lstf(FILENAME);
}