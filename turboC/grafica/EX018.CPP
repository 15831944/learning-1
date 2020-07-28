/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getmaxx si getmaxy
 * intorc coordonatele maxime x, respectiv y ale ecranului folosire
 * de driverul curent
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	char xrange[80], yrange[80];
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
	sprintf(xrange, "X valori cuprinse intre 0..%d", getmaxx());
	sprintf(yrange, "Y valori cuprinse intre 0..%d", getmaxy());
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy, xrange);
	outtextxy(midx,midy + textheight("W"), yrange);
	getch();
	closegraph();
	return 0;
}