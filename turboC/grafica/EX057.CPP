/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getarccoords
 * determina coordonatele ultimului apel arc (apelat cu arc si ellipse)
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct arccoordstype arcinfo;
	int midx, midy;
	int stangle = 45, endangle = 270;
	char sstr[80], estr[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	setcolor(getmaxcolor());
	arc(midx,midy,stangle,endangle,100);
	getarccoords(&arcinfo);
	sprintf(sstr,"*-(%d,%d)",arcinfo.xstart,arcinfo.ystart);
	sprintf(estr,"*-(%d,%d)",arcinfo.xend,arcinfo.yend);
	outtextxy(arcinfo.xstart,arcinfo.ystart,sstr);
	outtextxy(arcinfo.xend,arcinfo.yend,estr);
	getch();
	closegraph();
	return 0;
}