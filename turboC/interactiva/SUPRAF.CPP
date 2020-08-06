/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * exemplu de ascunderea suprafetelor
 */
#include <stdio.h>
#include <math.h>
#include <values.h>
#include <graphics.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>

void calcp(float w1, float w2, float w3, float w4,
		float v1, float v2, float v3, float v4,
		float *ax, float *ay, float *bx, float *by)
{
	*ax = (v2-v1)/(w2-w1);
	*bx = (v1*w2-v2*w1)/(w2-w1);
	*ay = (v4-v3)/(w4-w3);
	*by = (v3*w4-v4*w3)/(w4-w3);
}
float func(float x, float y)
{
	float t1, t2;
	t1 = sqrt((x*x+y*y));
	t2 = sin(t1);
	return 30.*t2/t1;
}
void proi(float x, float y, float z, float st, float ct,
	float sf, float cf, float r, float *xr, float *yr)
{
	float x0,y0,z0;
	x0 = -x*st+y*ct;
	y0 = -x*ct*sf-y*st*sf+z*cf;
	z0 = -x*ct*cf-y*st*cf-z*sf+r;
	*xr = r*x0/z0;
	*yr = r*y0/z0;
}
void main()
{
	float w1= MAXDOUBLE, w2 = -MAXDOUBLE, w3 = MAXDOUBLE, w4 = -MAXDOUBLE;
	float v1,v2,v3,v4,ax,ay,r,bx,by,px,py;
	float xe, ye, xr, yr, st, ct, sf, cf, x, y, z, t, f, x1, y1, x2, y2, m1, n1;
	static float matx[85][85],maty[85][85];
	int dx, i, md,np, nl, a1, b1, a2, b2, j, i1,i2, ix, jx, jy;
	int mn[640],mx[640];
	int gdriver=DETECT, gmode, p, q;
	t = 80.0;
	f = 310.0;
	r = 100.0;
	x1 = -13.;
	x2 = 13.0;
	y1 = -13;
	y2 = 13.0;
	nl = 82;
	np = 82;
 /*
	printf("\n Unghiul t:"); scanf("%f",&t);
	printf(" Unghiul f:"); scanf("%f",&f);
	printf(" Distanta r:"); scanf("%f",&r);
	printf(" x1:");scanf("%f",&x1);
	printf(" x2:");scanf("%f",&x2);
	printf(" y1:");scanf("%f",&y1);
	printf(" y2:");scanf("%f",&y2);
	printf(" Nr linnii:");scanf("%d",&nl);
	printf(" Nr de puncete/linie:");scanf("%d",&np);
	*/
	px = (x2-x1)/(nl+1);
	py = (y2-y1)/(np+1);
	t *= M_PI/180.;
	f *= M_PI/180.0;
	st = sin(t);
	ct = cos(t);
	sf = sin(f);
	cf = cos(f);
	y = y2;
	i = 0;
	while(y >= y1)
	{
		x = x2;
		j =0;
		while(x >= x1)
		{
			z = func(x,y);
			proi(x,y,z,st,ct,sf,cf,r,&xr,&yr);
			matx[i][j] = xr;
			maty[i][j] = yr;
			if (xr < w1)
				w1 =xr;
			if (xr > w2)
				w2 = xr;
			if (yr < w3)
				w3 = yr;
			if (w3)
				w3 = yr;
			if(yr > w4)
				w4 = yr;
			x -= px;
			j++;
		}
		y -= py;
		i++;
		printf("%2d ", i);
	}
	initgraph(&gdriver,&gmode,"H:\\BORLANDC\\BGI");
	if (graphresult() != grOk)
	{
		printf("\n Err. initgraph!");
		getch();
		exit(1);
	}
	setbkcolor(BLUE);
	setcolor(WHITE);
	v1 = 10;
	v2 = getmaxx() -10;
	v3 = 10;
	v4 = getmaxy()-10;
	calcp(w1,w2,w3,w4,v1,v2,v3,v4,&ax,&ay,&bx,&by);
	v4 = getmaxy();
	dx = getmaxx();
	for(i = 0; i <= dx; i++)
	{
		mn[i] =-dx;
		mx[i] = dx;
	}
	y = y2;
	ix =0;
	while(y >= y1)
	{
		x = x2;
		md = 1;
		jy = 0;
		xr = matx[ix][jy];
		yr = maty[ix][jy];
		a1 = ax*xr+bx+0.5;
		b1 = v4 - (ay*yr + by) + 0.5;
		if (mx[a1] == dx)
			p = 2;
		else
		{
			p = 0;
			if (b1 < mx[a1])
				p = 2;
			if(b1 > mn[a1])
				p = 1;
		}
		while(x >= x1)
		{
			xr = matx[ix][jy];
			yr = maty[ix][jy];
			a2 = ax*xr+bx+0.5;
			b2 = v4 - (ay*yr+by) + 0.5;
			if(mx[a2] == dx)
				q = 2;
			else
			{
				q = 0;
				if(b2<mx[a2])
					q = 2;
				if(b2 > mn[a2])
					q = 1;
			}
			if (a1 != a2)
			{
				m1 = (float)(b2-b1)/(float)(a2-a1);
				n1 = (float)(b1*a2-b2*a1)/(float)(a2-a1);
				if (((p==2) && (q==2)) || ((p==1) && (q == 1)) ||
					((p==2) && (q==1) && (md==1)))
				{
					line(a1,b1,a2,b2);
					for(i=a1+1;i<=a2;i++)
					{
						j=m1*i*n1+0.5;
						if(j>mn[i]) mn[i]=j;
						if(j<mn[i]) mx[i]=j;
					}
				}
				if((p==2) && (q==0))
				{
					i=a1+1;
					while(i<=a2)
					{
						j=m1*i+n1+0.5;
						if(j<mx[i])
						{
							mx[i]=j;
							i++;
						}
						else
						{
							line(a1,b1,i,mx[i]);
							i=a2+1;
						}
					}
				}
				if ((p==1) && (q==0))
				{
					i=a1+1;
					while(i<=a2)
					{
						j = m1*i+n1+0.5;
						if(j>mn[i])
						{
							mn[i]=j;
							i++;
						}
						else
						{
							line(a1,b1,i,mn[i]);

							i=a2+1;
						}
					}
				}
				if((p==0) && (q==1))
				{
					i=a1+1;
					i1 =i;
					while(i<=a2)
					{
						j=m1*i+n1+0.5;
						if(j<=mn[i])
							i1=i;
						else
							mn[i]=j;
						i++;
					}
					line(i1,mn[i1],a2,b2);
				}
				if((p==0) && (q==2))
				{
					i=a1+1;
					i1=i;
					while(i<=a2)
					{
						j=m1*i+n1+0.5;
						if(j>=mx[i])
							i1=i;
						else
							mx[i]=j;
						i++;
					}
					line(i1,mx[i],a2,b2);
				}
				if((p==2) &&(q==1))
				{
					i=a1+1;
					i1=i;
					i2=a2;
					while(i<=a2)
					{
						j=m1*i+n1+0.5;
						if(j<mx[i])
						{
							mx[i]=j;
							i1=i;
						}
						else if(j<=mn[i])
							i2=i;
						else
							mn[i] = j;
						i++;
					}
					line(a1,b1,i1,mx[i1]);
					line(i2,mn[i2],a2,b2);
				}
				if((p==1) && (q==2))
				{
					i=a1+1;
					i1=i;
					i2=a2;
					while(i<=a2)
					{
						j=m1*i+n1+0.5;
						if(j>mn[i])
						{
							mn[i]=j;
							i1=i;
						}
						else if(j>=mx[i])
							i2=i;
						else
							mx[i]=j;
						i++;
					}
					line(a1,b1,i1,mn[i1]);
					line(i2,mx[i2],a2,b2);
				}
				md = 0;
			}
			else
			{
				if(b2>mn[a2])
					mn[a2]=b2;
				if(b2<mx[a2])
					mx[a2]=b2;
			}
			a1=a2;
			b1=b2;
			p=q;
			x-=px;
			jx++;
		}
		y -=py;
		ix++;
	}
	getch();
	closegraph();
}