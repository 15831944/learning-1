/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * cleardevice
 * sterge ecranul grafic
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	setcolor(getmaxcolor());
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx, midy,"Apasa orice tasta pentru stergerea ecranului:");
	getch();
	cleardevice();
	outtextxy(midx,midy,"Apasa orice tasta pentru parasire:");
	getch();
	closegraph();
	return 0;
}