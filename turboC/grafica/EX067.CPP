/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * settextstyle
 * seteaza caracteristicile curente ale textului, tipul si dimensiunea
 * setului de caractere curent
 * daca functia setusercharsize nu a fost folosita, atunci valoare 0 pentru
 * charsize conduce la folosirea marimii implicite 4 a characterelor
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* numar de stiluri de text suportate */
char *fname[] = { "DEFAULT font", "TRIPLEX font", "SMALL font",
	"SANS SERIF font", "GHOTIC font"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int style, midx, midy;
	int size = 1;
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	/* bucla prin intermediul stilurilor de text */
	for(style = DEFAULT_FONT; style <= GOTHIC_FONT; style++)
	{
		cleardevice();
		if (style == TRIPLEX_FONT)
			size = 4;
		settextstyle(style, HORIZ_DIR, size);
		outtextxy(midx, midy, fname[style]);
		getch();
	}
	closegraph();
	return 0;
}