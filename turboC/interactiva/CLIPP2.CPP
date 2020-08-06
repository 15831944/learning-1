/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * clipping de poligon
 */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
struct punct {
	int x;
	int y;
};
enum reg {ST,DR,SUS,JOS};
int Cod(struct punct pi, enum reg much, int xst, int xdr, int ys, int yj)
{
	switch(much)
	{
		case ST:
			if(pi.x<xst)
				return 1;
			else
				return 0;
		case DR:
			if(pi.x>xdr)
				return 1;
			else
				return 0;
		case SUS:
			if(pi.y<ys)
				return 1;
			else
				return 0;
		case JOS:
			if(pi.y>yj)
				return 1;
			else
				return 0;
		default:
			return 1;
	}
}
struct punct intersect(struct punct p0, struct punct p1, enum reg much,
	 int xst, int xdr, int ys, int yj)
{
	static struct punct rez;
	switch(much)
	{
		case ST:
			rez.x = xst;
			rez.y = p0.y+(p1.y-p0.y)/(p1.x-p0.x)*(xst-p0.x);
			break;
		case DR:
			rez.x = xdr;
			rez.y = p0.y+(p1.y-p0.y)/(p1.x-p0.x)*(xdr-p0.x);
			break;
		case SUS:
			rez.y = ys;
			rez.x = p0.x + (p1.x-p0.x)/(p1.y-p0.y)*(ys-p0.y);
			break;
		case JOS:
			rez.y = yj;
			rez.x = p0.x+(p1.x-p0.x)/(p1.y-p0.y)*(yj-p0.y);
			break;
	}
	return rez;
}
void iesire(struct punct p0, struct punct p1, enum reg much, struct punct qs[1000],
	int& nv, int xst, int xdr, int ys, int yj)
{
	int cp0, cp1;
	struct punct ip;
	cp0 = Cod(p0,much,xst,xdr,ys,yj);
	cp1 = Cod(p1,much,xst,xdr,ys,yj);
	if (cp0+cp1 == 0)
	{
		qs[nv]=p1;
		nv +=1;
	}
	else if(cp0 == 0)
	{
		ip = intersect(p0,p1,much,xst,xdr,ys,yj);
		qs[nv] = ip;
		nv += 1;
	}
	else if(cp1 == 0)
	{
		ip = intersect(p0,p1,much,xst,xdr,ys,yj);
		qs[nv] = ip;
		qs[nv+1] =p1;
		nv +=2;
	}
}

int clipmuchie(struct punct q[], struct punct qs[], enum reg much,
		int n, int xst, int xdr, int ys, int yj)
{
	int i, nv  =0;
	for(i=1;i<=n;i++)
		iesire(q[i-1],q[i],much,qs,nv,xst,xdr,ys,yj);
	qs[nv] = qs[0];
	return nv;
}
void main(void)
{
	enum reg r;
	int xst, xdr, yj, ys, n, g, m, l1,l2,l3,l4;
	int gdriver = DETECT, gmode;
	struct punct p[1000],p1[1000],p2[1000],p3[1000],p4[1000];
	printf("\n stinga=");
	scanf("%d",&xst);
	printf("\n dreapta=");
	scanf("%d",&xdr);
	printf("\n sus=");
	scanf("%d",&ys);
	printf("\n jos=");
	scanf("%d",&yj);
	printf("\n n=");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("x[%d]=",i+1);
		scanf("%d",&p[i].x);
		printf("y[%d]=",i+1);
		scanf("%d",&p[i].y);
	}
	p[n].x = p[0].x;
	p[n].y = p[0].y;
	l1 = clipmuchie(p,p1,ST,n,xst,xdr,ys,yj);
	l2 = clipmuchie(p1,p2,DR,l1,xst,xdr,ys,yj);
	l3 = clipmuchie(p2,p3,JOS,l2,xst,xdr,ys,yj);
	l4 = clipmuchie(p3,p4,SUS,l3,xst,xdr,ys,yj);
	initgraph(&gdriver,&gmode,"H:\\BORLANDC\\BGI");
	rectangle(xst,ys,xdr,yj);
	setcolor(3);
	int vecp[200];
	for(i=0;i<l4+1;i++) {
		vecp[2*i]=p4[i].x;
		vecp[2*i+1]=p4[i].y;
	}
	drawpoly(l4+1,vecp);
	getch();
	closegraph();
}