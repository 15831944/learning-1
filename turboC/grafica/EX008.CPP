/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Intoarce numarul maxim de moduri grafice pentru driver-ul curent
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	/* autodetectie cerere */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	char modestr[80];
	/* initializare grafica si o varibilelor locale */
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
	midx = getmaxx() /2;
	midy = getmaxy()/2;
	/* determinarea informatiilor de mod si convertirea la un sir */
	sprintf(modestr,"Acest driver suporta modurile 0...%d", getmaxmode());
	/* afisare informatii */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(midx, midy, modestr);
	/* curatare completa */
	getch();
	closegraph();
	return 0;
}