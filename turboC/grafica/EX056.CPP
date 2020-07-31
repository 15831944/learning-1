/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * sector
 * deseneaza si hasureaza un sector de elipsa
 * daca unghiul de inceput este 0 si unghiul de final este 359 atunci
 * va desena o elipsa completa
 * unghiurile trebuie date in sens invers acelor de ceasornic, 0 grade
 * corespunde orei 3 iar 90 de grade orei 12
 * dupa apel cursorul grafic va fi plasat in centrul elipsei
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy, i;
	int stangle = 45, endangle = 135;
	int xrad = 100, yrad = 50;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* bucla prin intermediul stilului de hasurare */
	for (i = EMPTY_FILL; i < USER_FILL; i++)
	{
		setfillstyle(i, getmaxcolor());
		sector(midx, midy, stangle, endangle, xrad, yrad);
		getch();
	}
	closegraph();
	return 0;
}