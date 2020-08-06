/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 *  fractal mandelbrot
 * ex: (a=0.2,b=0.54) (a=0.1,b=0.602) (a=0.1,b=0.6024)
 */
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
void desen(int color)
{
	float x=0, wr =0, wl=0, y = 0, wt =0, wb =0;
	float newx, newy, a=1., b=0.9;
	int i, xe, ye, vl =0, vr=400, vb=0, vt =400;
	int gdriver = DETECT, gmode;
	clrscr();
	printf("\n Dati a si b ");
	scanf("%f%f",&a,&b);
	for(i =0; i < 1000; i++)
	{
		newx = x*x - y*y +a;
		newy = 2*x*y + b;
		if (newx < wl)
			wl = newx;
		else
			if (newx > wr)
				wr = newx;
		if (newy < wb)
			wb = newy;
		else
			if (newy > wt)
				wt = newy;
		x = newx;
		y = newy;
	}
	x = y = 0;
	clrscr();
	fflush(stdin);
	printf("\n wl = %f wr = %f wt = %f wb = %f", wl, wr, wt, wb);
	getch();
	initgraph(&gdriver,&gmode,"H:\\BORLANDC\\BGI");
	for(i = 0; i < 10000; i++)
	{
		newx = x*x - y*y + a;
		newy = 2*x*y + b;
		x = newx;
		y = newy;
		xe = (vr-vl)/(wr-wl)*x + (vl*wr-vr*wl)/(wr-wl);
		ye = (vt-vb)/(wt-wb)*y +  (vb*wt-vt*wb)/(wt-wb);
		putpixel(xe,ye,i%color);
	}
	getch();
	closegraph();
}
void main(void)
{
	desen(4);
}