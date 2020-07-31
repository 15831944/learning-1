/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * program de animatie utilizind tehnica stergerii figurii prin
 * redesenarea ei cu culoarea fondului
 */
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

#define PI 3.14
#define N 3
#define LAT 100
#define LAT2 LAT/2
#define H 200
#define D 50

int dy = 300; /* numar de pozitii distincte */
int gdriver, gmode, errorcode;
int xx[N][5],yy[N][5]; /* coordonatele proiectiei virfurilor */
int i ,j;
void proiectii_cabinet(void);
void desen(int i);
int main(void)
{
	gdriver = DETECT;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setlinestyle(DASHED_LINE,0,1);
	proiectii_cabinet();
	for(j = 0; j <= 29;j++)
		for(i = 0; i <= N -1;i++)
		{
			setcolor(BLUE);
			desen(i);
			delay(200);
			setcolor(getbkcolor());
			desen(i);
		}
	getch();
	closegraph();
	return 0;
}
/* se genereaza proiectiile virfurilor pentru cele n=3 pozitii distincte */
void proiectii_cabinet(void)
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
		xx[0][j] = (int)(x[j]+r*z[j]);
		yy[0][j] = dy - (int)(y[j]+r*z[j]);
	}
	for(i = 1; i<=N; i++)
	{
		c = cos(u);
		s = sin(u);
		for(j = 0; j <= 3; j++) /* roteste cu alfa virfurile bazei */
		{
			x1 = xc + (x[j]-xc)*c-(z[j]-zc)*s;
			z1 = zc + (x[j] -xc)*s + (z[j]-zc)*c;
			xx[i][j] = (int)(x1 + r*z1); /* coordonatele proiectie */
			yy[i][j] = dy - (int)(y[j] + r*z1);
		}
		u = u + alfa;
		/* virful piramidei nu se roteste */
		xx[i][4] = xx[0][4];
		yy[i][4] = yy[0][4];
	}
}
/* deseneaza piramida din pozitia i */
void desen(int i)
{
	int j;
	moveto(xx[i][0],yy[i][0]);
	for(j = 1; j <=3; j++)
		lineto(xx[i][j],yy[i][j]);
	lineto(xx[i][0],yy[i][0]);
	for(j = 0; j <=3; j++)
	{
		moveto(xx[i][4],yy[i][4]);
		lineto(xx[i][j],yy[i][j]);
	}
}