/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * _graphgetmem si _graphfreemem
 * aloca si elibereaza memorie grafica
 * valoare maxima este de 65521
 * este bine ca utilizatorul sa nu foloseasca aceste functii
 * daca vrea este posibil cu ajutorul functiilor proprii similare
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	clrscr();
	printf("Apasa orice tasta pentru initierea modului grafic:");
	getch();
	clrscr();
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx() /2;
	midy = getmaxy()/2;
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(midx,midy, "Apasa orice tasta pentru iesirea din modul grafic:");
	getch();
	closegraph();
	return 0;
}
/* chemata de programul ce executa functii grafice pentru alocare dinamica */
void far * far _graphgetmem(unsigned size)
{
	printf("La apelare _graphgetmem aloca %d octeti.\n", size);
	printf("Apasa orice tasta:");
	getch();
	printf("\n");
	return farmalloc(size);
}
/* chemata de programul ce executa frunctii grafice pentru eliberarea memoriei */
void far * far_graphfreemem(void far * ptr, unsigned size)
{
	printf("La apeelare _graphfreemem elibereaza %d octeti.\n",size);
	printf("Apasa orice tasta:");
	getch();
	printf("\n");
	farfree(ptr);
}