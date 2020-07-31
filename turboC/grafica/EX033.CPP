/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getpalettesize
 * intoarce dimensiunea tabelei de culori a paletei
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	char psize[80];
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* converteste informatia despre marimea paletei intr-un sir */
	sprintf(psize,"Aceasta paleta are %d intari modificabile.",
		getpalettesize());
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx, midy, psize);
	getch();
	closegraph();
}