/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * ellipse
 * Deseneaza conturul unui arc de elipsa
 * daca unghiin =0 si unghifin = 359 atunci se traseaza intreaga elipsa
 * unghiurile se dau in grae hexazecimale, in sens invers arcelor de
 * ceasornic, 0 grade corespunde orei 3 iar 90 de grade orei 12
 * dupa apel cursorul va fi plasat in centrul elipsei desenate
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int stangle = 0, endangle = 360;
	int xradius = 100, yradius = 50;
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
	setcolor(getmaxcolor());
	ellipse(midx,midy, stangle, endangle, xradius, yradius);
	getch();
	closegraph();
	return 0;
}