/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * outtext
 * afiseaza un text in fereastra curenta, relativ la pozitia cursorului
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* muta cursorul in centrul ecranului */
	moveto(midx,midy);
	outtext("Acesta ");
	outtext(" este ");
	outtext("un ");
	outtext("text.");
	getch();
	closegraph();
	return 0;
}