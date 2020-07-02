/*
 * alinierea textului:
 * orizontal:
 * LEFT_TEXT 0, PC la stinga txtului
 * CENTER_TEXT 1 PC in centrul textului
 * RIGHT_TEXT 2 PC la dreapta textului
 * vertical:
 * BOTTOM_TEXT 0 PC la baza textului
 * CENTER_TEXT 1 PC in centrul textului
 * TOP_TEXT 2 PC deasupra textului
 * tipuri de caractere:
 * DEFAULT_FONT 0 8x8 bit-mapped font
 * TRIPLEX_FONT 1 stroked triplex font
 * SMALL_FONT 2 stroked small font
 * SANS_SERIF 3 stroked sans serif font
 * GOTHIC_FONT 4 stroked gotic font
 * directia textului:
 * HORIZ_DIR 0 sting-dreapta
 * VERT_DIR 1 jos-sus
 */
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
void main()
{
	int gdriver = VGA;
	int gmode = VGAHI;
	initgraph(&gdriver,&gmode,"H:\\BORLANDC\\BGI");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	moveto(10,10);
	outtext("Acesta este primul text.");
	outtext("Acesta este al doilea text.");
	settextjustify(CENTER_TEXT, BOTTOM_TEXT);
	outtextxy(getmaxx()/2,getmaxy()/2, "Acest test este in centrul ferestrei");

	char text[140];
	sprintf(text,"Pozita curenta pe ecran: x =%d, y=%d",getx(),gety());
	outtextxy(10,10,text);
	getch();
	closegraph();
}