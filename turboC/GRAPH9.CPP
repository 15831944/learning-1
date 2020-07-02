/*
 * Modele de hasurare:
 * EMPTY_FILL 0 umple cu culoarea de font
 * SOLID_FILL 1 umple uniform (toti pixelii)
 * LINE_FILL 2 hasurata orizontale
 * LTSLASH_FILL 3 hasura ///
 * SLASH_FILL 4 hasura /// linii groase
 * BKSLASH_FILL 5 hasura \\\ groase
 * LTBKSLASH_FILL 6 hasura \\\
 * HATCH_FILL 7 hasura in cruce ++
 * XHATCH_FILL 8 hasura in cruce oblica
 * INTERLEAVE_FILL 9 hasura cu intretesere
 * WIDE_DOT_FILL 10 umplere cu puncte rare
 * CLOSE_DOT_FILL 11 umple cu puncte dese
 * USER_FILL 12 model definit de programator
 */
#include <graphics.h>
#include <conio.h>

void main()
{
	int x,y, dx, dy, i;
	char model[]={0xff,0xff,0xff,0xff,0,0,0,0};
	int gdriver = VGA;
	int gmod= VGAHI;
	initgraph(&gdriver, &gmod,"H:\\BORLANDC\\BGI");
	/* stilul de linie si culoarea de desenare */
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(LIGHTRED);
	/* dimensiunea dreptunghiurilor */
	x = (getmaxx() +1)/6;
	y=getmaxy()/2;
	/* afiseaza 12 dreptunghiuri hasurate cu cele 12 modele standard*/
	for (i = 0; i < 12; i++) {
		dx = x *(i%6);
		dy = y *(i/6);
		setfillstyle(i, LIGHTGREEN);
		bar3d(dx,dy,dx+x-10,dy+y-10,0,0);
	}
	getch();
	/* sterge ecranul */
	cleardevice();
	/* defineste modelul propriu */
	setfillpattern(model, LIGHTGREEN);
	/* deseneaza si hasureaza un dreptunghi cu acest model */
	rectangle(0,0,x,y);
	setfillstyle(USER_FILL, LIGHTRED);
	getch();
	closegraph();
}