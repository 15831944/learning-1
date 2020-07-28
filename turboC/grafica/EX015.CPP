/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setviewport
 * clip = taierea este decluplata deci din desen nu se va mai
 * vedea partea din afara ferestre.
 * dupa apelul ei toate coordonatele sunt relative cu aceasta
 * fereastra
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define CLIP_ON 1 /* activare clipping in fereastra */
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru orprire:");
		getch();
		exit(1);
	}
	setcolor(getmaxcolor());
	outtextxy(0,0,"* <-- (0,0) in fereastra implicita");
	/* creaza o fereastra mai mica */
	setviewport(50,50,getmaxx()-50,getmaxy()-50, CLIP_ON);
	outtextxy(0,0,"* <-- (0,0) in fereastra mica");
	getch();
	closegraph();
	return 0;
}