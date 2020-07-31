/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * moverel
 * muta pozitia cursorului grafic la o distanta relativa
 * dx pe axa x si dy pe axa y, fata de pozitia curenta
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	char msg[80];
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* muta pozitia curenta la locatia (20,30) */
	moveto(20,30);
	putpixel(getx(),gety(),getmaxcolor());
	sprintf(msg," (%d,%d)",getx(),gety());
	outtextxy(20,30,msg);
	/* muta punctul la o distanta relativa fata de pozitia curenta */
	moverel(100,100);
	putpixel(getx(),gety(),getmaxcolor());
	sprintf(msg," (%d,%d)",getx(),gety());
	outtext(msg);
	getch();
	closegraph();
	return 0;
}