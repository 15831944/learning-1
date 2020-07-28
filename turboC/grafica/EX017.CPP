/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * clearviewport
 * sterge fereastra grafica curenta
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define CLIP_ON 1
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int ht;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setcolor(getmaxcolor());
	ht = textheight("W");
	outtextxy(0,0,"* <-- (0,0) in fereastra mica");
	outtextxy(0,2*ht,"Apasa orice tasta pentru stergerea ferestrei:");
	getch();
	clearviewport();
	outtextxy(0,0,"Apasa orice tasta pentru parasire:");
	getch();
	closegraph();
	return 0;
}