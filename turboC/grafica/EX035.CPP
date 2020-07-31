/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setrgbpalette
 * defineste culorile pentru placa grafica IBM-8514
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = VGA, gmode = VGAHI, errorcode;
	struct palettetype pal;
	int i, ht, y, xmax;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* realizarea unei copii a paletei */
	getpalette(&pal);
	/* creaza o scala gri */
	for (i =0; i < pal.size; i++)
		setrgbpalette(pal.colors[i],i*4,i*4,i*4);
	/* afisarea scalei gri */
	ht = getmaxy()/16;
	xmax = getmaxx();
	y = 0;
	for (i = 0; i< pal.size; i++)
	{
		setfillstyle(SOLID_FILL, i);
		bar(0,y, xmax, y+ht);
		y +=ht;
	}
	getch();
	closegraph();
	return 0;
}