/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setfillpattern
 * selecteaza modelul de hasurare definit de utilizator
 * cei 8x8 biti din reprezentarea interna a variabilei upattern
 * definesc un patrat de 8x8 pixeli din mode, fiecare bit egal
 * cu 1 determinind aprinderea pixelului corespunzator
 * modelul implicit este SOLIF_FILL de culoarea curenta
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int maxx, maxy;
	/* un model de hasurare definit de utilizator */
	char pattern[8]={0x00,0x70,0x20,0x27,0x24,0x24,0x07,0x00};
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
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
	/* selectarea unui model de hasurare definit de utilizator */
	setfillpattern(pattern, getmaxcolor());
	bar(0,0,maxx,maxy);
	getch();
	closegraph();
	return 0;
}