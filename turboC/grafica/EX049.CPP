/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * drawpoly
 * deseneaza conturul unui poligon
 * in cazul unui polinom inchis de n virfuri trebuie date n+1
 * perechi de coordonate
 * coordonatele initiale si cele finale trebuie sa coincida pentru
 * ca poligonul sa fie inchis
 * nu modifica cursorul grafic
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int maxx, maxy;
	/* tabloul poligonului */
	int poly[10];
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();
	poly[0] = 20; /* primul virf */
	poly[1] = maxy/2;
	poly[2] = maxx - 20; /* al doilea virf */
	poly[3] = 20;
	poly[4] = maxx - 50; /* al treilea virf */
	poly[5] = maxy - 20;
	poly[6] = maxx/2; /* al patrulea virf */
	poly[7] = maxy/2;
	/* drawpoly nu inchide automat poligonul deci trebuie sa-l inchidem noi */
	poly[8] = poly[0];
	poly[9] = poly[1];
	drawpoly(5, poly);
	getch();
	closegraph();
	return 0;
}