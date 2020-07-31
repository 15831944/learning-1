/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
 /* fractali */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

int n=6, gdriver = DETECT, gmode, errorcode, i;
int xa[4] = {400,300,200,300};
int ya[4] = {300,200,300,400};
int xb[4] = {300, 200, 300, 400};
int yb[4] = {200,300,400,300};

double rx, ry;
int fractal(int m, int xa, int ya, int xb, int yb);
int main(void)
{
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	rx = sqrt(3)/8;
	ry = -rx;
	setlinestyle(SOLID_LINE,0,3);
	setbkcolor(WHITE);
	setcolor(BLUE);
	rectangle(190,200,410,400);
	setlinestyle(SOLID_LINE,0,1);
	for (i =0; i <=3 ;i++)
	{
		switch(i)
		{
			case 2:
				ry = -ry;
				break;
			case 3:
				rx = -rx;
				break;
			case 0:
				ry = -ry;
				break;
		}
		circle(xa[i],ya[i],2);
		circle(xb[i],yb[i],2);
		fractal(n,xa[i],ya[i],xb[i],yb[i]);
	}
	getch();
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	floodfill(300,300,BLUE);
	delay(1000);
	/* se schimba paleta de culori */
	for (i = 0; i <= 15; i++)
	{
		if (i >2) setpalette(0,i-2);
		if(i <1) setpalette(1,i-1);
		setpalette(11,i);
		delay(1000);
	}
	graphdefaults();
	setbkcolor(WHITE);
	getch();
	closegraph();
	return 0;
}

int fractal(int n, int xa, int ya, int xb, int yb)
{
	int xc, yc, xm, ym; /* coordonatele punctelor C,M */
	if (n > 1)
	{
		xc = (int)((3*xa + xb)/4 + rx*abs(yb-ya)); /* pct C */
		yc = (int)((3*ya + yb)/4 + ry*abs(xb-xa));
		xm = (int)((xa + xb)/2); /* pct M */
		ym = (int)((ya + yb)/2);
		circle(xc,yc,2);
		circle(xm,ym,2);
		fractal(n-1, xa, ya, xc, yc);
		fractal(n-1,xc,yc,xm,ym);
		fractal(n-1,xm,ym,xb,yb);
	}
}