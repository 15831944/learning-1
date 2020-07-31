/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getpalette
 * determina informatia despre paleta curenta, numarul culorilor
 * si culorile corespunzatoare elementelor tabelei de culori a
 * paletei
 */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct palettetype pal;
	char psize[80], pval[20];
	int i, ht;
	int y = 10;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* realizeaza o copie a paletei */
	getpalette(&pal);
	/* converteste informatia paletei in siruri */
	sprintf(psize,"Paleta are %d intrari modificabile.", pal.size);
	outtextxy(0,y,psize);
	if(pal.size != 0)
	{
		ht = textheight("W");
		y += 2*ht;
		outtextxy(0, y, "Aici are valoarea curenta:");
		y += 2*ht;
		for(i = 0; i< pal.size; i++, y+=ht)
		{
			sprintf(pval,"paleta[%02d]:0x%02X",i, pal.colors[i]);
			outtextxy(0,y,pval);
		}
	}
	getch();
	closegraph();
	return 0;
}