/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * intoarce un pointer la un sir continind numele modului
 * grafic specificat prin numarul sau
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	/* autodetectie cerere */
	int gdriver = DETECT, gmode , errorcode;
	int midx, midy, mode;
	char numname[80], modename[80];
	/* initierea grafica si a variabilelor locale */
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	/* citirea rezultatului initializarii */
	errorcode = graphresult();
	if (errorcode != grOk) /* exista eroare */
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);/* terminare cu un cod de eroare */
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* determinarea numarului de moduri si a numelui sirurilor */
	mode = getgraphmode();
	sprintf(numname,"%d este numarul modului curent.", mode);
	sprintf(modename, "%s este modul grafic curent.", getmodename(mode));
	/* afisare informatie */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(midx, midy, numname);
	outtextxy(midx, midy + 2*textheight("W"), modename);
	/* curatire completa */
	getch();
	closegraph();
	return 0;
}