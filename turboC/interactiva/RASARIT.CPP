/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * program de pseudoanimatie care prezinta rasarirea soarelui utilizind
 * tehnica de manipulare a paletei de culori
 */
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#define PI 3.141592
static double wl,wr,wt,wb;
static int vl, vr,vt,vb;
void setwindow(double newwl, double newwt, double newwb, double newwr)
{
	wl = newwl;
	wb = newwb;
	wt = newwt;
	wr = newwr;
}
void setviewport(int newvl, int newvt, int newvb, int newvr)
{
	vl = newvl;
	vt = newvt;
	vb = newvb;
	vr = newvr;
}
void scalare(double *x, double *y)
{
	*x = (vr-vl)/(wr-wl)**x+(vl*wr - vr*wl)/(wr-wl);
	*y = (vt-vb)/(wt-wb)**y+(wb*wt - vt*wb)/(wt-wb);
}
int main(void)
{
	int i,a,b;
	double x,y,phi;
	int mode, driver= DETECT, errorcode;
	initgraph(&driver,&mode,"H:\\BORLANDC\\BGI");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		return 1;
	}
	setpalette(1,LIGHTBLUE);
	setcolor(15);
	rectangle(0,0,getmaxx(),0.8*getmaxy());
	setfillstyle(SOLID_FILL,15);
	floodfill(10,10,15);
	a = getmaxx()/2.;
	b = .8*getmaxy();
	setpalette(0,BLUE);
	setcolor(0);
	rectangle(0,0.8*getmaxy(),getmaxx(),getmaxy());
	setfillstyle(SOLID_FILL,0);
	floodfill(a-2,b+2,0);
	for(i =1,phi = 7*PI/180.;i < 14; i++)
	{
		x = a*cos(phi);
		y = b*sin(phi);
		setwindow(-320.,380.,0.,320.);
		setviewport(20,25,360,620);
		scalare(&x,&y);
		setpalette(i,LIGHTBLUE);
		setcolor(i);
		circle(x,y,20);
		phi +=(14.*PI/180.);
		setfillstyle(SOLID_FILL,i);
		floodfill(x,y,i);
	}
	getch();
	for(i = 1; i < 14; i++)
	{
		setpalette(i, YELLOW);
		delay(200);
		setpalette(i,LIGHTBLUE);
	}
	getch();
	closegraph();
	return 0;
}