/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Restabileste modul text existent inaintea modului grafic
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
	/* initializare grafica si a variabilelor locale */
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	/* citirea rezultatului initializarii */
	errorcode = graphresult();
	if (errorcode != grOk) /* exista o eroare */
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);/* terminare cu un cod de eroare */
	}
	x = getmaxx()/2;
	y = getmaxy()/2;
	/* iesirea unui mesaj */
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x, y, "Press any key to exit graphics:");
	getch();
	/* restabileste modul text */
	restorecrtmode();
	printf("Suntem din nou in modul text.\n");
	printf("Apasa orice tasta pentru intoarcerea la modul grafic:");
	getch();
	/* intoarcere la modul grafic */
	setgraphmode(getgraphmode());
	/* iesirea unui mesaj */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(x, y, "Suntem iarasi in modul grafic.");
	outtextxy(x,y + textheight("W"), "Apasa orice tasta pentru oprire:");
	/* curatare completa */
	getch();
	closegraph();
	return 0;
}