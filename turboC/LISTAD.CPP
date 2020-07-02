/*
 * lista simplu inlantuita in alocare dinamica
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nlsi {
	/* informatia din nodul listei */
	double data;
	/* adresa nodului urmator */
	struct nlsi *urm;
} lnod;

lnod *list(void);
lnod *insr(lnod *p, double v);
double extr(lnod *p);
void aflist(lnod *lsi);

void main()
{
	lnod *rldi;
	/* apeleaza functia de creare a listei */
	rldi = list();
	printf("lista:");
	aflist(rldi);
	printf("\nextrag cap %10.4lf\n",extr(rldi));
	insr(rldi,10.11);
	aflist(rldi);
}

/* insereaza v dupa nodul indicat de p */
lnod *insr(lnod *p, double v)
{
	lnod *q; /* pointer catre noul nod */
	q = (lnod *)malloc(sizeof(lnod));
	if (q != NULL) {
		q -> data = v;
		q -> urm = p -> urm;
		p -> urm = q;
	}
	return q;
}

/* extrage nodul aflat dupa p, intoarce valoarea */
double extr(lnod *p)
{
	double v; /* valoarea extrasa */
	lnod *q; /* pointer catre nodul extras */
	q = p -> urm;
	v = q -> data;
	p -> urm = q -> urm;
	free(q);
	return v;
}

/*creaza lista inlantuita in ordine crescatoare a valorilor */
lnod * list(void)
{
	lnod *lsi, *p, *q;
	double v;
	/* initializare lista */
	lsi = (lnod *)malloc(sizeof(lnod));
	lsi -> urm = NULL;
	/* ciclu de introducere a valorilor */
	for(;;) {
		printf("\nIntroduceti valoarea: ");
		if (scanf("%lf", &v) != 1) {
			fflush(stdin);
			printf("Sfirsitul introducerii ? [y/n]:");
			if (getche() == 'y')
				return lsi;
		}
		p = (lnod *)malloc(sizeof(lnod));
		p -> data = v;
		/* cauta pozitia de inserare pentru ordonare crescatoare */
		for (q = lsi; q -> urm != NULL && q -> urm -> data < v; q = q -> urm);
		/* q = pozitia elementului dupa care se face inserarea */
		p -> urm = q -> urm;
		q -> urm = p;
	}
}

/* afiseaza lista */
void aflist(lnod *ls)
{
	lnod *p;
	for (p = ls -> urm; p != NULL; p = p -> urm)
		printf("%10.4lf ", p->data);
}
