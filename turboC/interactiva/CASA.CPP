/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * casa
 */
#include <stdio.h>
#include <process.h>
#include <math.h>
#include <stdio.h>
#include <alloc.h>
#include <graphics.h>
#include <conio.h>
struct punct {
	int pct;
	struct punct *urm;
};
void calcp(double w1, double w2, double w3, double w4,
	double v1, double v2, double v3, double v4,
	double& ax, double& ay, double& bx,double& by)
{
	ax = (v2-v1)/(w2-w1);
	bx = (v1*w2-v2*w1)/(w2-w1);
	ay = (v4-v3)/(w4-w3);
	by = (v3*w4-v4*w3)/(w4-w3);
}
void adaug(struct punct*& fata, int pf)
{
	struct punct *tmp,*nou;
	nou = (struct punct *)malloc(sizeof(struct punct));
	nou -> pct = pf;
	nou -> urm = NULL;
	if (fata == NULL) fata = nou;
	else
	{
		tmp = fata;
		while(tmp->urm != NULL)
			tmp = tmp -> urm;
		tmp -> urm = nou;
	}
}

void main()
{
	FILE *pf;
	double tx[50],ty[50], w1, w2, w3, w4, v1, v2, v3, v4, ax, ay, bx, by;
	int leg[50][50], dt, dm, n, m, i, j, pfi, ad, a1, a2, a3, gata;
	double xr, yr, xo, yo,zo,x,y,z,t,f,r,xd,yd,mx,my,mz,o1,o2,o3,tg,fg;
	double plg[50][3],px,py,x1e,y1e,x2e,y2e,st,sf,ct,cf,p1,p2,p3;
	double q1,q2,q3,prod_scal, vo1,vo2,vo3;
	struct punct *temp,*fata[50];
	char c;
	if((pf = fopen("td1.dat","rt")) == NULL)
	{
		printf("\n fis inexistent!!!");
		exit(1);
	}
	fscanf(pf,"%d%d",&n,&m);
	mx=my=mz=0;
	for(i=0;i<n;i++)
	{
		fscanf(pf,"%lf%lf%lf",&x,&y,&z);
		plg[i][0]=x;
		plg[i][1]=y;
		plg[i][2]=z;
		if(x>mx)
			mx = x;
		if(y>my)
			my = y;
		if(z>mz)
			mz = z;
	}
	for(i=0;i<m;i++)
	{
		fata[i]=NULL;
		do
		{
			fscanf(pf,"%d",&pfi);
			if(pfi)
				adaug(fata[i],pfi);
		} while(pfi);
	}
	for(i =0;i <n;i++)
	{
		plg[i][0] = plg[i][0]-mx/2;
		plg[i][1] = plg[i][1]-my/2;
		plg[i][2] = plg[i][2]-mz/2;
	}
	r = 10*sqrt(mx*mx+my*my+mz*mz);
	printf("\n Unghiul t=");scanf("%lf",&tg);
	printf("\n Unghiul f=");scanf("%lf",&fg);
	gata = 0;
	dt = DETECT;
	initgraph(&dt,&dm,"H:\\BORLANDC\\BGI");
	setbkcolor(WHITE);
	setcolor(BLUE);
	do
	{
		t = M_PI*tg/180;
		f = M_PI*fg/180;
		st = sin(t);
		sf = sin(f);
		ct = cos(t);
		cf = cos(f);
		o1 = r*cf*ct;
		o2 = r*cf*st;
		o3 = r*sf;
		w1 = 1e20;
		w2 = -1e20;
		w3 = 1e20;
		w4 = -1e20;
		for(i =0; i<n;i++)
		{
			for(j = 0;j<n;j++) leg[i][j] =1;
			x = plg[i][0];
			y = plg[i][1];
			z = plg[i][2];
			xo = -x*st+y*ct;
			yo = -x*ct*sf-y*st*sf+z*cf;
			zo = -x*ct*cf-y*st*cf-z*sf+r;
			xr = r*xo/zo;
			yr = r *yo/zo;
			tx[i] = xr;
			ty[i] = yr;
			if (w1>xr) w1 = xr;
			if (w2<xr) w2 = xr;
			if (w3>yr) w3 = yr;
			if (w4<yr) w4 = yr;
		}
		v1 = 10;
		v2 = getmaxx()-10;
		v3 = 10;
		v4 = getmaxy() - 10;
		calcp(w1,w2,w3,w4,v1,v2,v3,v4,ax,ay,bx,by);
		for(j =0; j<m;j++)
		{
			a1 = fata[j]-> pct;
			ad = a1;
			a2 = fata[j] -> urm -> pct;
			a3 = fata[j] -> urm -> urm -> pct;
			p1 = plg[a2-1][0] - plg[a1-1][0];
			p2 = plg[a2-1][1] - plg[a1-1][1];
			p3 = plg[a2-1][2] - plg[a1-1][2];
			q1 = plg[a3-1][0] - plg[a1-1][0];
			q2 = plg[a3-1][1] - plg[a1-1][1];
			q3 = plg[a3-1][2] - plg[a1-1][2];
			vo1 = o1 - plg[a1-1][0];
			vo2 = o2 - plg[a1-1][1];
			vo3 = o3 - plg[a1-1][2];
			prod_scal = vo1*(p2*q3 -q2*p3) + vo2 * (p3*q1 - q3*p1) + vo3*(p1*q2-q1*p2);
			if(prod_scal>0)
			{
				x1e = ax*tx[a1-1]+bx;
				y1e = v4 - ay*ty[a1-1]-by;
				xd = x1e;
				yd = y1e;
				temp = fata[j];
				while(temp -> urm != NULL)
				{
					temp = temp -> urm;
					a2 = temp -> pct;
					x2e = ax * tx[a2-1]+bx;
					y2e = v4-ay*ty[a2-1]-by;
					if (leg[a1-1][a2-1] && leg[a2-1][a1-1])
					{
						line((int)x1e,(int)y1e,(int)x2e,(int)y2e);
						leg[a1-1][a2-1] = 0;
					}
					a1 = a2;
					x1e = x2e;
					y1e = y2e;
				}
				a2 = ad;
				x2e = xd;
				y2e = yd;
				if(leg[a1-1][a2-1] && leg[a2-1][a1-1])
				{
					line((int)x1e,(int)y1e,(int)x2e,(int)y2e);
					leg[a1-1][a2-1] =0;
				}
			}
		}
		do
		{
			c = getch();
			switch(c)
			{
				case 27:
					gata = 1;
					break;
				case '\0':
				{
					c = getch();
					switch(c)
					{
						case 72:
						{
							fg += 10;
							cleardevice();
							break;
						}
						case 80:
						{
							fg -= 10;
							cleardevice();
							break;
						}
						case 75:
						{
							tg -= 10;
							cleardevice();
							break;
						}
						case 77:
						{
							tg +=10;
							cleardevice();
							break;
						}
					}
				}
			}
		}
		while(c != 27 && c!=72 && c!=80 && c!=75 && c!=77);
	}
	while(!gata);
	closegraph();
}