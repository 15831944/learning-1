/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getdefaultpalette
 * intoarce definitia structurii paletei
 *(gama de culori a paletei)
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	/* structura pentru intoarcerea copiei paletei */
	struct palettetype far *pal = (void *)0;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setcolor(getmaxcolor());
	/* intoarce un pointer la paleta implicita */
	pal = getdefaultpalette();
	for (int i =0; i< 16; i++)
	{
		printf("colors[%d] = %d\n",i, pal->colors[i]);
		getch();
	}
	getch();
	closegraph();
	return 0;
}