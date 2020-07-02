/*
 * lista FIFO in implementerea secventiala
 */
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct {
	/* tabloul de N elemente */
	int tab[N];
	/* numarul curent de elemente din lista */
	int ncrt;
	/* indexul primului element din lista */
	int prim;
} fifo;

/* initializeaza lista ls */
void init(fifo * ls)
{
	ls -> ncrt = ls -> prim = 0;
}

/* test daca lista este vida */
int nl_vida(fifo *ls)
{
	return (ls -> ncrt > 0);
}

/* test daca lista nu este plina */
int nl_plina(fifo *ls)
{
	return (ls -> ncrt < N);
} /* ncrt == 100 --> lista plina */

/* adauga la lista ls valoarea k */
int adaug(fifo *ls, int k)
{
	if (nl_plina(ls)) {
		(ls -> tab)[(ls -> prim + ls -> ncrt) %N] = k;
		(ls -> ncrt)++;
		/* afisare pentru test */
		printf("Lista are %d elemente\n", ls -> ncrt);
		return 1;
	}
	else {
		printf("Lista plina !\n");
		return 0;
	}
}

/* extrage din lista ls si memoreaza valoarea la adresa k */
int extrag(fifo *ls, int *k)
{
	if (nl_vida(ls)) {
		*k = (ls -> tab)[ls -> prim];
		ls -> prim = (ls -> prim + 1)%N;
		(ls -> ncrt)--;
		/* afisare pentru test */
		printf("Lista are %d elemente\n", ls -> ncrt);
		return 1;
	}
	else {
		printf("Lista goala !\n");
		return 0;
	}
}

void main()
{
	int i, v;
	fifo l; /* declararea liste locale l */
	fifo *lp; /* pointer lp pentru liste fifo */
	/* initializeaza lista l */
	init (&l);
	/* creeaza o lista ca variabila dinamica */
	lp =(fifo *)malloc(sizeof(fifo));
	/* initializeaza lista lp */
	init(lp);
	puts ("Extrage din lista !");
	extrag(&l,&v);
	puts("Adauga la lista lp 3 elemente");
	for(i = 0; i < 3 && nl_plina(lp); i++) {
		printf("%d\n", 10+i);
		adaug(lp,10+i);
	}
	puts("Extrage toate elementele din lp");
	while(nl_vida(lp)) {
		extrag(lp,&v);
		printf("%d\n",v);
	}
	/* eloimina variabila dinamica */
	free(lp);
}

