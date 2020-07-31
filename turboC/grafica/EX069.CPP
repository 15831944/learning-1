/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * textwidth
 * intoarce latimea unui text in pixeli
 * functia textwidht este pentru a fi utilizata cu functiile grafice
 * de iesire text outtext si outtextxy
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int x = 0, y = 0;
	int i;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	y = getmaxy()/2;
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	for(i = 1; i <11;i++)
	{
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,i);
		sprintf(msg,"Dimensiunea: %d",i);
		outtextxy(x,y, msg);
		x += textwidth(msg);
	}
	getch();
	closegraph();
	return 0;
}