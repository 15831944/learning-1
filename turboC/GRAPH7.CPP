/*
 * stiluri de linie : SOLID_LINE 0 linie continua, DOTTED_LINE 1 linie
 * punctata, CENTER_LINE 2 linie intrerupta, DASHED_LINE 3 linie intrerupta,
 * USERBIT_LINE 4 stil definit de utilizator
 * grosimi ale liniei: NORM_WIDTH 1 1 pixel latime, THICK_WIDTH 3 3 pixeli latime
 */
#include <graphics.h>
#include <conio.h>
void main()
{
	/* modul VGAHI */
	int i;
	int gdriver = DETECT, gmod;
	initgraph(&gdriver, &gmod, "H:\\BORLANDC\\BGI");
	/* linii in stilurile standard */
	for (i =0; i < 4; i++) {
		setlinestyle(i, 0, NORM_WIDTH);
		moveto(100,100);
		lineto(400,100+100*i);
	}
	/* linie-punct definita de programator */
	moveto(100,100);
	setlinestyle(USERBIT_LINE, 0xff18, NORM_WIDTH);
	lineto(100,400);
	getch();
	closegraph();
}