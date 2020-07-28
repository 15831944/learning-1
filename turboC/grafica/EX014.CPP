/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * functia getgraphmode
 * inainte de apleare trebuie apelata una din functiile
 * initgraph sau setgraphmode
 * intoarce modul grafic curent
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy, mode;
	char numname[80],modename[80];
	initgraph(&gdriver, &gmode,  "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru orpire:");
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	mode = getgraphmode();
	sprintf(numname,"%d este numarul modului curent.", mode);
	sprintf(modename,"%s este modul grafic curent.",getmodename(mode));
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy,numname);
	outtextxy(midx, midy+2*textheight("W"), modename);
	getch();
	closegraph();
	return 0;
}