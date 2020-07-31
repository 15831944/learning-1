/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setwritemode
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
	int gdriver = DETECT, gmode, errorcode;
	int xmax, ymax;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	xmax = getmaxx();
	ymax = getmaxy();
	/* selectarea modului de desenare XOR */
	setwritemode(XOR_PUT);
	line(0,0,xmax,ymax);
	getch();
	/* selectarea modului de scriere scriere peste (overwrite) */
	setwritemode(COPY_PUT);
	line(0,0, xmax, ymax);
	getch();
	closegraph();
	return 0;
}