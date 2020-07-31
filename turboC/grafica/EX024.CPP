/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setfillstyle
 * seteaza modelul de hasurare si culoare
 * afecteaza : bar, fillpoly, bar3d, sector si elipse
 */
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
/* nume de stiluri de hasurare suportate */
char *fname[] = {"EMPTY_FILL", "SOLID_FILL", "LINE_FILL", "LTSLASH_FILL",
	"SLASH_FILL", "BKSLASH_FILL", "LTBKSLASH_FILL", "HATCH_FILL",
	"XHATCH_FILL", "INTERLEAVE_FILL", "WIDE_DOT_FILL", "CLOSE_DOT_FILL",
	"USER_FILL"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int style, midx, midy;
	char stylestr[40];
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	for (style = EMPTY_FILL; style < USER_FILL; style++)
	{
		/* selectarea stilului de hasurare */
		setfillstyle(style, getmaxcolor());
		/* conversisa stilului intr-un sir */
		strcpy(stylestr, fname[style]);
		bar3d(0,0, midx-10,midy, 0,0);
		outtextxy(midx, midy, stylestr);
		getch();
		cleardevice();
	}
	getch();
	closegraph();
	return 0;
}