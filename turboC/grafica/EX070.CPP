/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * textheight
 * intoarce inaltimea textului in pixeli
 * textheight este pentru a fi utilizata cu functiile grafice de iesire
 * text outtext si outtextxy
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int y = 0;
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
	/* deseneaza unui text pe ecran */
	for (i = 1; i < 11; i++)
	{
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,i);
		sprintf(msg,"Dimensiunea: %d",i);
		outtextxy(1,y,msg);
		y +=textheight(msg);
	}
	getch();
	closegraph();
	return 0;
}