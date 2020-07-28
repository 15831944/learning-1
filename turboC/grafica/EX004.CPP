/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Functie face sa apara ecranul dinainte initializarii
 * modului grafic si elibereaza zona ocupata din HEAP
 * pentru sistemul grafic
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	/* autodetectie cerere */
	int gdriver = DETECT, gmode, errorcode;
	int x, y;
	/* initializare mode grafic */
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	/* citirea rezultatului intializarii */
	errorcode = graphresult();
	if (errorcode != grOk) /* s-a gasit o eroare */
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);/* terminare cu un cod de eroare */
	}
	x = getmaxx()/2;
	y = getmaxy()/2;
	/* iesirea unui mesaj */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(x, y, "Apasa o tasta pentru inchiderea sistemului grafic:");
	/* asteapta apasare unei taste */
	getch();
	/* inchiderea sistemului grafic */
	closegraph();
	printf("Acum va fi din nou in modul text\n");
	printf("Apasa orice tasta pentru oprire:");
	getch();
	exit(0);
}