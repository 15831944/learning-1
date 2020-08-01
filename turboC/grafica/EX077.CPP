/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * program de animatie utilizind tehnica memorarii imaginii
 * cu getimage() si a scrierii sale cu putimage() avind cel de-al
 * de-al patrulea argument egal cu XOR_PUT
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
int dx = 155, dy = 300; /* numar de pozitii distincte */
int gdriver, gmode, errorcode;
int xx[5],yy[5]; /* coordonatele proiectiilor virfurilor */
int dim, i, j;
void far *mem[N];
void generarea_imaginilor(void);
void desen();
int main(void)
{
	gdriver = DETECT;
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
	generarea_imaginilor();
	delay(50);
	putimage(0,0,mem[2],XOR_PUT);
	for(j = 0; j <=28;j++)
		for(i = 0; i <= N-1; i++)
		{
			putimage(0,0,mem[i],XOR_PUT);/* deseneaza imagine*/
			delay(100);
			putimage(0,0,mem[i],XOR_PUT);/* sterge imagine*/
		}
	getch();
	closegraph();
	return 0;
}
/* se genereaza proiectiile virfurilor pentru cele n= 3 pozitii distincte */
void generarea_imaginilor(void)
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
	desen();
	dim = imagesize(0,0,dx,dy); /* calculeaza dimensiunea imaginii*/
	if ((mem[0] = farmalloc(dim)) == NULL)
	{
		closegraph();
		printf("Eroare: nu este suficient spatiu heap.\n");
		exit(1);
	}
	getimage(0,0,dx,dy,mem[0]); /* salvaza imaginea in mem[0] */
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
		putimage(0,0,mem[i-1], XOR_PUT); /* sterge imaginea */
		desen();
		if ((mem[i] = farmalloc(dim)) == NULL)
		{
			closegraph();
			printf("Eroare: nu este suficient spatiu heap.\n");
			exit(1);
		}
		getimage(0,0,dx,dy,mem[i]);
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
