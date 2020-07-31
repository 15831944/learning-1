/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * deseneaza o priectie axonometrica izomatrica o suprafata data de
 * ecuatia z = sin(sqrt(x^2+y^2)) x in [a,b] si y in [c,d]
 * coordonatele proiectiilor punctelor care genereaza suprafata, se
 * pastreaza in matricile xx[i,j],yy[i,y] i=1,2..,NX, j=1,2,..,NY cu
 * NX*NY numarul de puncte ale retelei
 */
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NX 25
#define NY 25
#define PI 3.14
/* reteaua are NX*NY puncte*/
double f(double x, double y);
double radiani(double u);
int i,j, gdriver, gmode, errorcode, dy;
double a = -12, b= 13, c= -12, d = 13;
double alfa = 165, beta = -135, gama = 135;
double c1,c2,c3,s1,s2,s3,x,y,z,ux,uy;
double xmin,xmax,ymin,ymax,al, be, ga;
/* coordonatele proiectiilor punctelor suprafetei */
double xx[NX][NY],yy[NX][NY];
int main(void)
{
	al = radiani(alfa);
	be = radiani(beta);
	ga = radiani(gama);
	c1 = cos(al); s1 = sin(al);
	c2 = cos(be); s2 = sin(be);
	c3 = cos(ga); s3 = sin(ga);
	clrscr();
	ux = abs(b-a)/(NX-1); /* unitatea pe axa absciselor */
	uy = abs(d-c)/(NY-1); /* unitatea pe axa ordonatelor */
	/* se determina coordonatele proiectiilor punctelor suprafetei */
	x = a; y = c; z = f(x,y);
	xx[0][0] = x*c1 + y*c2 + z*c3;
	yy[0][0] = x*s1 + y*s2 + z*s3;
	xmin = xx[0][0]; xmax = xmin;
	ymin = yy[0][0]; ymax = ymin;
	for (i = 0; i <= NX -1; i++)
	{
		y = c;
		for (j = 0; j <= NY-1; j++)
		{
			z = f(x,y);
			xx[i][j] = x*c1 + y*c2 + z*c3;
			yy[i][j] = x*s1 + y*s2 + z*s3;
			if (xmin > xx[i][j])
				xmin = xx[i][j];
			else {
				if (xmax < xx[i][j])
					ymin = yy[i][j];
			}
			if (ymin > yy[i][j])
				ymin = yy[i][j];
			else {
				if (ymax < yy[i][j])
					ymax = yy[i][j];
			}
			y = y + uy;
		}
		x = x + ux;
	}
	gdriver = DETECT;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setcolor(BLUE);
	/* desenarea suprafetei */
	ux = (xmax - xmin)/(getmaxx()-200); /* unitatea de reprezentare pe Ox */
	uy = (ymax - ymin)/(getmaxy()-200); /* unitatea de reprezentare pe Oy */
	dy = getmaxy() - 100;
	for (i = 0; i <= NX -1; i++)
	{
		moveto((int)((xx[i][0]-xmin)/ux),dy-(int)((yy[i][0] - ymin)/uy));
		for(j = 0; j <= NY -1; j++)
			lineto((int)((xx[i][j] - xmin)/ux), dy - (int)((yy[i][j] - ymin)/uy));
	}
	for(j = 0; j <= NY -1; j++)
	{
		moveto((int)((xx[0][j] - xmin)/ux), dy - (int)((yy[0][j] - ymin)/uy));
		for (i = 0; i <= NY -1; i++)
			lineto((int)((xx[i][j] - xmin)/ux), dy - (int)((yy[i][j] - ymin)/uy));
	}
	getch();
	closegraph();
	return 0;
}

double f(double xf, double yf)
{
	return sin(sqrt(xf*xf+yf*yf));
}
double radiani(double u)
{
	return u/180*PI;
}