/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getlinesettings
 * determina tipul, modelul si grosimea curenta a liniei
 */

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* nume de stiuri de linie suportate */
char *lname[] = {"SOLID_LINE", "DOTTED_LINE", "CENTER_LINE",
	"DASHED_LINE","USERBIT_LINE"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct linesettingstype lineinfo;
	int midx, midy;
	char lstyle[80], lpattern[80], lwidth[80];
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* determina informatia despre setarile curente ale liniei */
	getlinesettings(&lineinfo);
	/* converteste informatia liniei in siruri */
	sprintf(lstyle,"%s este stiluyl de linie.",lname[lineinfo.linestyle]);
	sprintf(lpattern,"0x%X este modelul de linie definit de utilizator",
		lineinfo.upattern);
	sprintf(lwidth,"%d este grosimea liniei.",lineinfo.thickness);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy, lstyle);
	outtextxy(midx, midy + 2*textheight("W"), lpattern);
	outtextxy(midx, midy + 4*textheight("W"),lwidth);
	getch();
	closegraph();
	return 0;
}