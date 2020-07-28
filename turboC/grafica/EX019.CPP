/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getviewsettings
 * determina informatiile despre fereastra curenta.
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
char *clip[]= {"OFF", "ON"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct viewporttype viewinfo;
	int midx, midy, ht;
	char topstr[80],botstr[80], clipstr[80];
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
	getviewsettings(&viewinfo);
	sprintf(topstr,"(%d, %d) este coltul de sus stinga al ferestrei.",
		viewinfo.left, viewinfo.top);
	sprintf(botstr,"(%d, %d) este coltul din dreapta jos al ferestrei.",
		viewinfo.right, viewinfo.bottom);
	sprintf(clipstr,"Clipirea este data de %s.",clip[viewinfo.clip]);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	ht = textheight("W");
	outtextxy(midx, midy, topstr);
	outtextxy(midx, midy + 2*ht, botstr);
	outtextxy(midx, midy+4*ht, clipstr);
	getch();
	closegraph();
	return 0;
}