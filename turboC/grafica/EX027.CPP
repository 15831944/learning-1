/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getfillpattern
 * copiaza in memorie modelul de hasurare definit de utilizator
 * pozitionat anterior cu setfillpattern
 * daca anterior nu a fost apelata functia setfillpattern, in
 * tabelul lui getfillpattern va fi inscrisa valoare 0xFF
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int maxx, maxy;
	char pattern[8]= {0x00, 0x70,0x20,0x27,0x25,0x27,0x04,0x04};
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();
	setcolor(getmaxcolor());
	/* selectarea modelului de hasurare definit de utilizator */
	setfillpattern(pattern, getmaxcolor());
	bar(0,0,maxx,maxy);
	getch();
	/* determinarea modelului curent de hasurare definit de utilizator */
	getfillpattern(pattern);
	/* schimbam modelul */
	pattern[4] -=1;
	pattern[5] -=3;
	pattern[6] +=3;
	pattern[7] -=4;
	/* selectem noul nostru model */
	setfillpattern(pattern, getmaxcolor());
	bar(0,0,maxx,maxy);
	getch();
	closegraph();
	return 0;
}