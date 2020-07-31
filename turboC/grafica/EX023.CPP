/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * floodfill
 * hasureaza cu modelul si culoarea actuale o regiune de ecran
 * definita printr-un punct interior si culoare frontierei
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int maxx, maxy;
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();
	/* selectare culoare de desenare */
	setcolor(getmaxcolor());
	/* selectarea culorii de umplere */
	setfillstyle(SOLID_FILL,getmaxcolor());
	/* desenarea unei borduri in jurul ecranului */
	rectangle(0,0,maxx, maxy);
	circle(maxx/3, maxy/2, 50);
	circle(maxx/2, 20, 100);
	circle(maxx-20, maxy-50,75);
	circle(20,maxy-20, 25);

	getch();
	/* umplerea regiunii marginite */
	floodfill(2,2,getmaxcolor());

	getch();
	closegraph();
	return 0;
}