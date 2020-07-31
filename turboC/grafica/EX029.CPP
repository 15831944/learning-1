/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setcolor
 * seteaza culoarea curenta de desenare
 */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
	int gdriver = EGA, gmode = EGAHI, errorcode;
	int color, maxcolor, x, y;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* indexul maxim al culorii suportate */
	maxcolor = getmaxcolor();
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	x = getmaxx()/2;
	y = getmaxy()/2;
	/* bucla prin intermediul culorilor disponibile */
	for(color = 1; color <= maxcolor; color++)
	{
		cleardevice();
		/* selectarea unei noi culori de desenare */
		setcolor(color);
		sprintf(msg,"Culoarea de desenare: %d", color);
		outtextxy(x,y,msg);
		getch();
	}
	closegraph();
	return 0;
}