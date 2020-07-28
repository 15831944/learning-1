/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Reseteaza toate setarile grafice la valorile lor implicite
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	/* autodetectie cerere */
	int gdriver = DETECT, gmode, errorcode;
	int maxx, maxy;
	/* initializarea grafica si a varibilelor locale */
	initgraph(&gdriver, &gmode,"H:\\borlandc\\bgi");
	/* citirea rezultatului initializarii */
	errorcode = graphresult();
	if (errorcode != grOk) /* exista o eroare */
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);/* terminare cu un cod de eroare */
	}
	maxx = getmaxx();
	maxy = getmaxy();
	/* iesire linie cu setare neimplicite */
	setlinestyle(DOTTED_LINE, 0, 3);
	line(0,0, maxx, maxy);
	outtextxy(maxx/2, maxy/3, "Inainte cu valorile implicite sa fie restaurate.");
	getch();
	/* restabilire valori implicite pentru toate */
	graphdefaults();
	/* stergere ecran */
	cleardevice();
	/* iesire linie cu setarile implicite */
	line(0,0,maxx, maxy);
	outtextxy(maxx/2, maxy/3, "Dupa restaurearea valorilor implicite.");
	/* curatare completa */
	getch();
	closegraph();
	return 0;
}