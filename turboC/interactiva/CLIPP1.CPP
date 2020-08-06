/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * exemplu de clipping al unui segment
 */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
struct punct {
	int x;
	int y;
};
int xst, xdr, yj, ys;
struct punct p1, p2, cp1, cp2;
unsigned int c1, c2;
unsigned int Cod(struct punct z)
{
	unsigned int dc;
	dc = 0;
	if (z.x < xst)
		dc = dc + 1;
	if (z.x > xdr)
		dc = dc + 2;
	if (z.y > yj)
		dc = dc + 4;
	if (z.y < ys)
		dc = dc + 8;
	return dc;
}
void Introduce_Date(void)
{
	printf("\n xst=");
	scanf("%d",&xst);
	printf("\t xdr=");
	scanf("%d",&xdr);
	printf("\n yj=");
	scanf("%d",&yj);
	printf("\t ys=");
	scanf("%d",&ys);
	printf("\n x1=");
	scanf("%d",&p1.x);
	printf("\t y1=");
	scanf("%d",&p1.y);
	printf("\n x2=");
	scanf("%d",&p2.x);
	printf("\t y2=");
	scanf("%d",&p2.y);
	int gmode, gdriver = DETECT;
	initgraph(&gdriver,&gmode,"H:\\BORLANDC\\BGI");
	moveto(xst,yj);
	lineto(xdr,yj);
	lineto(xdr,ys);
	lineto(xst,ys);
	lineto(xst,yj);
}
struct punct IntSt(struct punct& cz, unsigned int x)
{
	int yc;
	if((x&1) == 1)
	{
		yc = (p1.y + (p2.y-p1.y)/(p2.x-p1.x)*(xst-p1.x));
		if ((yc <=yj) && (yc>=ys))
		{
			cz.x = xst;
			cz.y = yc;
		}
	}
	return cz;
}
struct punct IntDr(struct punct& cz,unsigned int x)
{
	int yc;
	if ((x & (1 << 1)) == 2)
	{
		yc = (p1.y+(p2.y-p1.y)/(p2.x-p1.x)*(xdr-p1.x));
		if((yc<=yj) &&(yc >= ys))
		{
			cz.x = xdr;
			cz.y = yc;
		}
	}
	return cz;
}
struct punct IntJos(struct punct& cz, unsigned int x)
{
	int xc;
	if ((x & (1 << 2)) == 4)
	{
		xc = (p1.x+(p2.x-p1.x)/(p2.y-p1.y)*(yj-p1.y));
		if ((xc >=xst) && (xc<=xdr))
		{
			cz.x = xc;
			cz.y = yj;
		}
	}
	return cz;
}
struct punct IntSus(struct punct& cz, unsigned int x)
{
	int xc;
	if ((x & (1 << 3)) == 8)
	{
		xc = (p1.x+(p2.x-p1.x)/(p2.y-p1.y)*(ys-p1.y));
		if ((xc>=xst) && (xc<= xdr))
		{
			cz.x = xc;
			cz.y = ys;
		}
	}
	return cz;
}
struct punct Gaseste(struct punct z)
{
	static struct punct cz;
	unsigned int c;
	c=Cod(z);
	if(c == 0)
		cz = z;
	else {
		cz = IntSt(cz,c);
		cz = IntDr(cz,c);
		cz = IntJos(cz,c);
		cz = IntSus(cz,c);
	}
	return cz;
}
void main(void)
{
	Introduce_Date();
	c1 = Cod(p1);
	c2 = Cod(p2);
	if ((c1 | c2) == 0)
		line(p1.x,p1.y,p2.x,p2.y);
	else if ((c1 & c2) != 0)
		outtextxy(380,380,"Segment invizibil");
	else
	{
		cp1 = Gaseste(p1);
		cp2 = Gaseste(p2);
		line(cp1.x,cp1.y,cp2.x,cp2.y);
	}
	getch();
	closegraph();
}