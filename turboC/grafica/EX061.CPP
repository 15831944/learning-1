/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * deseneaza un catelus utilizaind 13 curbe Bspline
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
void curba(void);
int pas(void);
double a,b,c,p,u;
/* coordonatele puntelor de control */
int x[123] = {
	90,77,71,71,75,85,80,68,50,32,
	25,25,29,34,53,80,90,90,97,110,
	130,170,189,210,225,236,244,249,250,249,
	241,230,210,200,194,204,206,209,206,200,
	189,197,182,165,140,115,90,75,83,100,
	120,155,180,197,87,83,86,100,120,137,
	140,140,141,155,165,185,195,194,189,94,
	91,97,112,129,133,133,101,99,103,113,
	125,129,128,145,147,155,170,187,187,183,
	151,157,170,181,178,175,125,125,130,146,
	149,140,127,125,113,118,125,130,140,148,
	152,160,118,130,135,140,152,130,133,137,
	137,141,144};
int y[123] = {
	152,130,85,65,45,33,21,14,14,25,
	45,60,75,85,115,145,152,152,160,168,
	173,171,162,148,136,121,105,85,65,45,
	25,18,20,33,46,55,65,85,130,145,
	162,47,68,76,80,76,66,50,38,23,
	17,17,30,47,60,78,105,127,127,109,
	80,80,95,125,132,125,105,85,58,65,
	90,110,118,105,90,78,71,80,94,99,
	95,85,78,78,90,110,118,107,85,65,
	78,95,101,92,78,72,65,70,76,76,
	65,60,63,65,54,49,45,38,36,45,
	49,55,49,45,43,45,49,40,43,40,
	40,43,40};
/* numarul punctelor de control de pe fiecare curba */
int n[13] = {17,24,7,6,15,7,7,7,6,8,8,5,6};
int dy = 300, d,q,i,k,l,max,j,jj,xx,yy,m,v;
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setbkcolor(WHITE);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	settextstyle(2,0,5);
	l = -1;
	for (m = 0; m <= 12; m++)
	{
		j = l + 1;
		moveto(x[j],dy-y[j]);
		lineto((int)((x[j]+x[j+1])/2),(int)(dy -(y[j]+y[j+1])/2));
		for(i = 0; i <=n[m] -3;i++)
		{
			k = j + 1;
			l = k + 1;
			curba();
			j = k;
		}
		lineto(x[l],dy - y[l]);
		delay(1000);
	}
	setfillstyle(SOLID_FILL,RED);
	pieslice(105,222,0,360,5);
	pieslice(158,218,0,360,5);
	getch();
	closegraph();
	return 0;
}
void curba(void)
{
	p = 1/pas();
	u = 0;
	for(jj = 1; jj <=pas(); jj++)
	{
		a = 1 -u;
		a = a*a/2;
		c = u*u/2;
		b = 1 - a - c;
		xx = (int)(x[j]*a + x[k]*b + x[l]*c);
		yy = dy - (int)(y[j]*a + y[k]*b + y[l]*c);
		lineto(xx,yy);
		u = u + p;
	}
}
int pas(void)
{
	max = 0;
	for (q = j+1;q <= j+2;q++)
	{
		d = abs(x[q]-x[q-1]);
		if (d> max) max = d;
		d = abs(y[q] -y[q-1]);
		if (d > max) max = d;
	}
	return max + 5;
}