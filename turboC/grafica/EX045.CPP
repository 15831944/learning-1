/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * lineto
 * deseneaza un segment de dreapta din pzotia curenta
 * a cursorului grafic pina la punctul de coordonate
 * (x,y)
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
	moveto(20,30);
	sprintf(msg," (%d,%d)",getx(),gety());
	outtextxy(20,30,msg);
	/* deseneaza o linie la (100,100) */
	lineto(100,100);
	sprintf(msg," (%d,%d)",getx(),gety());
	outtext(msg);
	getch();
	closegraph();
	return 0;
}