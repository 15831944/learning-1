/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * registerbgifont
 * inregistreaza setul de caractere pentru
 * linkeditare si returneaza numarul setului de caractere respectiv
 * sau un cod de eroare daca setul de caractere specificat este incorect
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	errorcode = registerbgifont(triplex_font);
	if (errorcode < 0)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy,"The TRIPLEX FONT");
	getch();
	closegraph();
	return 0;
}