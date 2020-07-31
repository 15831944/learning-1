/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getcolor
 * intoarce culoarea de desenare curenta
 * pozitionata de sercolor
 */
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int color, midx, midy;
	char colname[35],colorS[20];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
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
	/* determinarea culorii culorii curente de desenare */
	color = getcolor();
	itoa(color, colorS, 10);
	sprintf(colname,"%s este culoare de desenare curenta.", colorS);
	outtextxy(midx,midy, colname);
	getch();
	closegraph();
	return 0;
}