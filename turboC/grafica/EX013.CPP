/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getdrivername()
 * intorace un pointer la numele driverului grafic curent.
 */
#include<graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	/* memoreaza numele dispozitivului driver */
	char *drivername;
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);
	}
	setcolor(getmaxcolor());
	/* determinarea numelui dispozitivului driver deschis */
	drivername = getdrivername();
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(getmaxx()/2,getmaxy()/2, drivername);
	getch();
	closegraph();
	return 0;
}