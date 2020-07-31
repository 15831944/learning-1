/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * putpizel
 * coloreaza un pizel specificatde coordonatele (x,y)
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define PIXEL_COUNT 1000
#define DELAY_TIME 100

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int i, x,y, color, maxx, maxy, maxcolor, seed;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxx = getmaxx() + 1;
	maxy = getmaxy() + 1;
	maxcolor  = getmaxcolor() + 1;
	while(!kbhit())
	{
		seed = random(32767);
		srand(seed);
		for (i = 0; i < PIXEL_COUNT; i++)
		{
			x = random(maxx);
			y = random(maxy);
			color = random (maxcolor);
			putpixel(x,y,color);
		}
		delay(DELAY_TIME);
		srand(seed);
		for (i = 0; i < PIXEL_COUNT;i ++)
		{
			 x = random(maxx);
			 y = random(maxy);
			 color = random(maxcolor);
			 if (color == getpixel(x,y))
				putpixel(x,y,0);
		}
	}
	getch();
	closegraph();
	return 0;
}