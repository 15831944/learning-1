/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * putimage
 * suprapune pe ecran (eventual intr-o alta pozitie) regiunea
 * salvata anterior cu getimage
 */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
#define ARROW_SIZE 10
void draw_arrow(int x, int y);
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	void *arrow;
	int x,y, maxx;
	unsigned int size;
	initgraph(&gdriver,&gmode,"h:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxx = getmaxx();
	x = 0;
	y = getmaxy()/2;
	draw_arrow(x,y);
	size = imagesize(x,y-ARROW_SIZE,x + (4*ARROW_SIZE),y+ARROW_SIZE);
	arrow = malloc(size);
	getimage(x,y-ARROW_SIZE,x + (4*ARROW_SIZE),y + ARROW_SIZE, arrow);
	while(!kbhit())
	{
		putimage(x,y-ARROW_SIZE,arrow,XOR_PUT);
		x +=ARROW_SIZE;
		if (x >= maxx)
			x = 0;
		putimage(x,y-ARROW_SIZE,arrow,XOR_PUT);
	}
	free(arrow);
	closegraph();
	return 0;
}
void draw_arrow(int x, int y)
{
	moveto(x,y);
	linerel(4*ARROW_SIZE,0);
	linerel(-2*ARROW_SIZE,-1*ARROW_SIZE);
	linerel(0,2*ARROW_SIZE);
	linerel(2*ARROW_SIZE,-1*ARROW_SIZE);
}
