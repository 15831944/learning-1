/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * circle
 * deseneaza contului unui cerc cu centrul si raza date
 * dupa apel cursorul grafic va fi plasat in centrul  cercului desenat
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int radius = 100;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	setcolor(getmaxcolor());
	circle(midx,midy,radius);
	getch();
	closegraph();
	return 0;
}