/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getfillsettings
 * determina informatiile despre modelul curent de hasurare
 * si culoare pozitionate cu setfillstyle
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
/* nume de stiluri de hasurare suportate */
char *fname[] = {"EMPTY_FILL", "SOLID_LINE", "LINE_FILL", "LTSLASH_FILL",
	"SLASH_FILL", "BKSLASH_FILL", "LTBKSLASH_FILL", "HATCH_FILL",
	"XHATCH_FILL", "INTERLEAVE_FILL", "WIdE_DOT_FILL", "CLOSE_DOT_FILL",
	"USER_FILL"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct fillsettingstype fillinfo;
	int midx, midy;
	char patstr[40], colstr[40];
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
	/* determina informatii despre modelul curent de hasurare si culoare */
	getfillsettings(&fillinfo);
	/* conversie informatii hasurate in siruri */
	sprintf(patstr,"%s este stilul de hasurare.", fname[fillinfo.pattern]);
	sprintf(colstr,"%d este culoarea de hasurare.",fillinfo.color);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy, patstr);
	outtextxy(midx, midy + 2*textheight("W"), colstr);
	getch();
	closegraph();
	return 0;
}