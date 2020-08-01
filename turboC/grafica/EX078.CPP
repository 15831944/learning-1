/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * program de animatie utilizind tehnica bazata pe functiile
 * de manipulare a paginilor video
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <alloc.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#define PI 3.14
#define N 3
#define LAT 100
#define LAT2 LAT/2
#define H 200
#define D 50
int dy = 200; /* numar de pozitii distincte */
int gdriver, gmode, errorcode;
int xx[5],yy[5]; /* coordonatele proiectiilor virfurilor */
int i, j;
void generarea_n_pagini_video(void);
void desen();
int main(void)
{
	gdriver = VGA;
	gmode = VGALO;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setlinestyle(DASHED_LINE,0,1);
	setcolor(BLUE);
	generarea_n_pagini_video();
	delay(50);
	for(j = 0; j <=28;j++)
		for(i = 0; i <= N-1; i++)
		{
			setvisualpage(i);
			delay(500);
		}
	getch();
	closegraph();
	return 0;
}
/* se genereaza proiectiile virfurilor pentru cele n= 3 pozitii distincte */
void generarea_n_pagini_video(void)
{
	int x[5] = {10, LAT +10, LAT+10,10,LAT2+10}; /* virfurile piramidei */
	int y[5] = {D,D,D,D,D+H};
	int z[5] = {0,0,LAT,LAT,LAT2};
	int xc = LAT2 + 10;
	int zc = LAT2; /* centrul bazei piramidei */
	int i,j;
	double sc,c,u,r,s,alfa, x1,z1;
	r = sqrt(2)/4;
	alfa = PI/2/N;
	u = alfa;
	/* coordonatele piramidei in pozitia initiala */
	for (j = 0; j <= 4; j++)
	{
		xx[j] = (int)(x[j]+r*z[j]);
		yy[j] = dy - (int)(y[j]+r*z[j]);
	}
	setactivepage(0);
	desen();
	setvisualpage(0);
	for(i = 1; i <= N-1; i++)
	{
		c = cos(u);
		s = sin(u);
		for(j = 0; j <= 3; j++) /* roteste cu alfa varfurile bazei */
		{
			x1 = xc + (x[j] -xc)*c - (z[j]-zc)*s;
			z1 = zc + (x[j] - xc)*s + (z[j] -zc)*c;
			xx[j] = (int)(x1 + r*z1);
			yy[j] = dy - (int)(y[j] + r*z1);
		}
		setactivepage(i);
		desen();
		setvisualpage(i);
		u = u + alfa;
	}
}

/* deseneaza piramida din pozitia i */
void desen(void)
{
	int j;
	moveto(xx[0],yy[0]);
	for(j = 1; j <=3; j++)
		lineto(xx[j],yy[j]);
	lineto(xx[0],yy[0]);
	for(j = 0; j <=3; j++)
	{
		moveto(xx[4],yy[4]);
		lineto(xx[j],yy[j]);
	}
}
