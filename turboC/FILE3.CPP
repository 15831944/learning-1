/*
 * citeste si afiseaza datele dintr-un fisier de intrare graf.txt
 * acesta contine laturile unui graf: nod initial nod final costul
 * asociat grafului
 */
#include <stdio.h>
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
	fprintf(fp, "%s %s %8.2f\n",r.ni,r.nf, r.cost);
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
		fscanf(fp,"%s %s %8.2f",r.ni,r.nf,&r.cost);
		printf("%3d %-10s %-10s %8.2f\n", i++, r.ni, r.nf,r.cost);
	}
	fclose(fp);
}

void main()
{

	adf(FILENAME);
	adf(FILENAME);
	lstf(FILENAME);
}