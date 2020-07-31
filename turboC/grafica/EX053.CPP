/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * fillellipse
 * deseneaza si umple (hasureaza) o elipsa
 * elipsa este umpluta utilizind modelul  de hasurare curent si culoare
 * de hasurare curenta
 * dupa aplel cursorul grafic va fi plast in centrul elipsei desenate
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int xcenter, ycenter, i;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	xcenter = getmaxx()/2;
	ycenter = getmaxy()/2;
	for(i = 0; i < 13; i++)
	{
		setfillstyle(i, WHITE);
		fillellipse(xcenter,ycenter, 100,50);
		getch();
	}
	closegraph();
	return 0;
}