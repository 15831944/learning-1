/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getbkcolor
 * intoarce culoarea curenta a fondului (pozitionata
 * cu functia setckcolor)
 */
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int bkcolor, midx, midy;
	char bkname[35];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode =  graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	setcolor(getmaxcolor());
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	bkcolor = getbkcolor();
	itoa(bkcolor, bkname, 10);
	strcat(bkname," este culoare de fond curenta.");
	outtextxy(midx, midy, bkname);
	getch();
	closegraph();
	return 0;
}
