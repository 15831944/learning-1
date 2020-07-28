/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setlinestyle
 * Functia are efect asupra functiilor: line, lineto, linerel,
 * rectangle, drawpoly, arc, circle, ellipse
 */
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
/* numele de tipuri de linii suportate */
char *lname[] = { "SOLID_LINE", "DOTTED_LINE","CENTER_LINE",
	"DASHED_LINE", "USERBIT_LINE"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int style, midx, midy, userpat;
	char stylestr[40];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafia: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* modelul de linie definita de utilizator in binar:"000000000000001" */
	userpat = 1;
	for (style=SOLID_LINE; style<=USERBIT_LINE; style++)
	{
		/* selecteaza tipul de linie */
		setlinestyle(style, userpat, 1);
		/* converteste tipul de linie intr-un sir */
		strcpy(stylestr, lname[style]);
		line(0,0,midx-10,midy);
		rectangle(0,0,getmaxx(),getmaxy());
		outtextxy(midx,midy, stylestr);
		getch();
		cleardevice();
	}
	closegraph();
	return 0;
}