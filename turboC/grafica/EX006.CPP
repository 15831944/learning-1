/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * functia seteaza toate atributele grafice la valoarea initiala
 * prin apelarea procedurilor setgraphmode si restorecrtmode
 * poate fi alternat modul  grafic cu modul text
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
	/* intializarea grafica si a variabilelor locale */
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	/* citirea rezultatului initializarii */
	errorcode = graphresult();
	if (errorcode != grOk) /* exista o eroare */
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru orprire:");
		getch();
		exit(1);/* terminare cu un cod de eroare */
	}
	x = getmaxx()/2;
	y = getmaxy()/2;
	/* iesirea unui mesaj */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(x,y, "Apasa orice tasta pentru iesirea din grafica:");
	getch();
	/* restaureaza sistemul la modul text */
	restorecrtmode();
	printf("Din nou in modul text.\n");
	printf("Apasa orice tasta pentru intoarcerea in modul grafic:");
	getch();
	/* intoarcere in modul grafic */
	setgraphmode(getgraphmode());
	/* iesirea unui mesaj */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(x, y, "Iarasi in modul grafic.");
	outtextxy(x, y + textheight("W"), "Apasa orice tasta pentru orprire.");
	/* curatire completa */
	getch();
	closegraph();
	return 0;
}