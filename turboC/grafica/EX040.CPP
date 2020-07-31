/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getx si gety
 * intorc coordonata x, respectiv coordonata y a pozitiei
 * curente a cursorului grafic
 */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* muta punctul in centrul ecranului */
	moveto(getmaxx()/2,getmaxy()/2);
	sprintf(msg, "(<-(%d,%d) este in acest loc.", getx(), gety());
	outtext(msg);
	getch();
	closegraph();
	return 0;
}