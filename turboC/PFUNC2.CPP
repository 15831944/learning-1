/*
 * ofera o solutie de realizare a unei functii de sortare a elementelor
 * unui tablou, utilizabila indiferent de tipul lor. se utilizeaza
 * algoritmul de sortare cu inserare
 */
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#define N 10
/*
 * consideram un tablou de valori reale double cu n elemente
 * pentru ordonarea crescatoare se poae scrie functia
 */
void insrt(double list[], int n)
{
	int i,j;
	double r;
	for(i = 1; i < n; i++) {
		r = list[i];
		/* r = elementul de inserat */
		for (j = i - 1; r < list[j] && j >= 0; j--)
			list[j+1] = list[j];
		list[j+1] =r;
	}
}

void insrtg(void *tab, size_t ne, size_t nd, int (*fcmp)(const void *, const void *))
{
	void *r;
	int i,j;
	r = malloc(nd);
	for (i = 1; i < ne; i++) {
		memmove(r, (char *)tab + nd*i,nd);
		for(j = i-1; (*fcmp)(r, (char *)tab + nd*j) && j >=0; j--)
			memmove((char *)tab + nd*(j+1), (char *)tab + nd*j ,nd);
		memmove((char *)tab + nd*(j+1), r, nd);
	}
	free(r);
}

int fcmp(const void *a, const void *b)
{
	/* introarce true daca a < b */
	if (*(double *)b - *(double *)a > 0) return 1;
	else return 0;
}

void main()
{
	double tab[N];
	int i;
	for(i = 0; i < N ;i++)
		tab[i] = 100.56 -i;
	puts("\nSirul inainte de sortare: ");
	for( i = 0; i < N; i++)
		printf("%lf ", tab[i]);
	insrtg(tab, N, sizeof(tab[0]), fcmp);
	/* echivalent cu insrt(t, N) */
	puts("\nDupa sortare: ");
	for( i = 0; i < N; i++)
		printf("%lf ", tab[i]);
	putchar('\n');
}