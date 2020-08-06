/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * curbe b-spline
 */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
struct b_spline {
	double ax, bx, cx, dx;
	double ay, by, cy, dy;
};
int nr_steps = 100, n;
int xa[100], ya[100];
float b_spline_x(float t, struct b_spline *bsp)
{
	return (bsp -> ax *t*t*t + bsp -> bx *t*t + bsp -> cx *t + bsp -> dx)/6.;
}
float b_spline_y(float t, struct b_spline *bsp)
{
	return (bsp -> ay *t*t*t + bsp -> by *t*t + bsp -> cy *t + bsp -> dy)/6.0;
}
void initial()
{
	int mode, driv = DETECT;
	initgraph(&driv,&mode,"H:\\BORLANDC\\BGI");
	setbkcolor(WHITE);
	setcolor(BLUE);
}
void input_the_points()
{
	int i;
	printf("\n Nr. de puncte=");
	scanf("%d",&n);
	for(i =0; i < n; i++)
	{
		printf("\n x[%d]=",i+1);
		scanf("%d",&xa[i+1]);
		printf("\n y[%d]=",i+1);
		scanf("%d",&ya[i+1]);
	}
}
void compute_b_spline_coef(int i, struct b_spline *bsp)
{
	bsp -> ax = -xa[i-1]+3*xa[i]-3*xa[i+1]+xa[i+2];
	bsp -> bx = 3*xa[i-1]-6*xa[i]+3*xa[i+1];
	bsp -> cx = -2*xa[i-1]+3*xa[i+1];
	bsp -> dx = xa[i-1]+4*xa[i]+xa[i+1];
	bsp -> ay = -ya[i-1]+3*ya[i]-3*ya[i+1]+ya[i+2];
	bsp -> by = 3*ya[i-1]-6*ya[i]+3*ya[i+1];
	bsp -> cy = -2*ya[i-1]+2*ya[i+1];
	bsp -> dy = ya[i-1] + 4*ya[i] + ya[i+1];
}
void plot_curve(float t1, float t2, int s, struct b_spline *bsp)
{
	int i;
	float t, delta_t,x1, y1, x2, y2;
	x1 = b_spline_x(t1,bsp);
	y1 = b_spline_y(t1,bsp);
	delta_t = (t2-t1)/s;
	for(i = 1; i < s; i++)
	{
		t = t1+i*delta_t;
		x2= b_spline_x(t, bsp);
		y2 = b_spline_y(t, bsp);
		line(x1,y1,x2,y2);
		x1 = x2;
		y1 = y2;
	}
}
void plot_b_spline(int nr_steps, struct b_spline *bsp)
{
	int i;
	for(i=2; i<n-1; i++)
	{
		compute_b_spline_coef(i, bsp);
		plot_curve(0,1,nr_steps, bsp);
	}
}
void main()
{
	struct b_spline bsp;
	int i;
	input_the_points();
	initial();
	for(i=1;i<=n;i++)
	{
		moveto(xa[i]-4,ya[i]-4);
		outtext("x");
	}
	plot_b_spline(nr_steps,&bsp);
	getch();
	closegraph();
}