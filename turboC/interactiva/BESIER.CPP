/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * curbe besier
 */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define POLY_MAX 100
void initial(float *xamx,float *xmin, float *ymax, float *ymin, int *nr_steps)
{
	printf("\n Introd rangul lui x: \n xmin=");
	scanf("%f",xmin);
	printf(" xmax=");
	scanf("%f",xamx);
	printf("\n Introdu rangului lui y: \n ymin=");
	scanf("%f",ymin);
	printf(" ymax=");
	scanf("%f",ymax);
	printf("\n Nr de pasi:");
	scanf("%d", nr_steps);
}
void input_the_points(float xa[], float ya[], int *n)
{
	int i;
	printf("\n Nr. de puncte=");
	scanf("%d",n);
	for(i = 0; i <*n; i++)
	{
		printf("\n x[%d]=",i+1);
		scanf("%f",&xa[i]);
		printf("\n y[%d]=", i+1);
		scanf("%f", &ya[i]);
	}
}
void compute_bez_coef(int nm1, float bez_coef[])
{
	int k,j;
	for (k =0; k<=nm1; k++)
	{
		bez_coef[k] =1;
		for(j = nm1; j >=k+1; j--)
			bez_coef[k] *=j;
		for(j = nm1 -k; j <=2; j--)
			bez_coef[k] /=j;
	}
}
float bez_blending_value(int nm1, int k, float u, float bez_coef[])
{
	float bv,v;
	int i;
	bv = bez_coef[k];
	for (i =1; i<=k; i++)
		bv *=u;
	v = 1 -u;
	for (i = 1; i<= nm1 -k ;i++)
		bv *= v;
	return bv;
}
void comp_bez_pt(int n, float xa[], float ya[], float u,
	float bez_coef[], float& x, float& y)
{
	int k, nm1;
	float bv;
	x =0,y=0;
	nm1 = n-1;
	for(k =0; k <= nm1; k++)
	{
		bv = bez_blending_value(nm1, k, u, bez_coef);
		x += (xa[k]*bv);
		y += (ya[k]*bv);
	}
}

void plot_bezier_curve(int n, float xa[], float ya[],
	float bez_coef[], int nr_steps)
{
	int i, nm1;
	float x1, x2,y1,y2, u;
	nm1 = n-1;
	compute_bez_coef(nm1, bez_coef);
	comp_bez_pt(n, xa, ya, 0, bez_coef, x1, y1);
	for (i = 0; i < nr_steps;i++)
	{
		u = (float)(i+1)/(float)nr_steps;
		comp_bez_pt(n,xa,ya,u,bez_coef,x2,y2);
		line(x1,y1,x2,y2);
		x1=x2;
		y1=y2;
	}
}
int main(void)
{
	int n, nr_steps, mode, driver=DETECT, i;
	float xmax, ymax, xmin, ymin, bez_coef[POLY_MAX];
	float xa[POLY_MAX],ya[POLY_MAX];
	initial(&xmax,&xmin,&ymax,&ymin,&nr_steps);
	input_the_points(xa,ya,&n);
	initgraph(&driver,&mode,"H:\\BORLANDC\\BGI\\");
	setbkcolor(WHITE);
	setcolor(BLUE);
	for(i = 0 ;i < n; i++)
	{
		moveto(xa[i]-4,ya[i]-4);
		outtext("x");
	}
	plot_bezier_curve(n,xa,ya,bez_coef,nr_steps);
	getch();
	getch();
	closegraph();
	return 0;
}