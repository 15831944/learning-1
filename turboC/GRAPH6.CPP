/*
 * Elementele paletei EGA/VGA: BLACK 0, BLUE 1, GREEN 2, CYAN 3,
 * RED 4, MAGENTA 5, BROWN 6, LIGHTGREY 7, DARKGRAY 8, LIGHTBLUE 9,
 * LIGHTGREEN 10, LIGHTCYAN 11, LIGHTRED 12, LIGHTMAGENTA 13, YELLOW 13,
 * WHITE 15
 * Culorile EGA/VGA: EGA_BLACK 0, EGA_BLUE 1, EGA_GREEN 2, EGA_CYAN 3,
 * EGA_RED 4, EGA_MAGENTA 5, EGA_BROWN 20, EGA_LIGHTGRAY 7, EGA_DARKGRAY 56,
 * EGA_LIGHTBLUE 57, EGA_LIGHTGREEN 58, EGA_LIGHTCYAN 59, EGA_LIGHTRED 60,
 * EGA_LIGHTMAGENTA 61, EGA_YELLOW 62, EGA_wHITE 63
 */
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void mira(void);
void mesaj(int,int);

void main()
{
	char t;
	int i,j;
	struct palettetype paleta;
	int gdriver = DETECT, gmod;
	initgraph(&gdriver, &gmod, "H:\\BORLANDC\\BGI");
	/* deseneaza mira de bare */
	mira();
	/* citeste paleta implicita */
	getpalette(&paleta);
	/* parcurge paleta */
	for(i = 0; i < 16; i++) {
		/* parcurge setul de culori */
		for(j = 0; j < 64; j++) {
			/* schimba elementul i din paleta in culoarea j */
			setpalette(i,j);
			if ((t = getch()) == 'p') break;
			if (t == 'm')
				mesaj(j, gmod);
		}
		/* revine la culoare originala a elementului i */
		setpalette(i, paleta.colors[i]);
		if (getch() == 's') break;
	}
	closegraph();
}

void mira()
{
	int x=0, color =0;
	int deltax, deltay;
	/* determinarea dimensiunile barei, in functie de rezolutie */
	deltax = (getmaxx() + 1) /16;
	deltay = getmaxy();
	/* deseneaza 16 bare in cele 16 culori ale paletei */
	for(color = 0; color < 16; color++) {
		setfillstyle(SOLID_FILL, color);
		bar(x, 0, x + deltax -1 , deltay);
		x +=deltax;
	}
}

void mesaj (int c, int mod)
{
	restorecrtmode();
	printf("Codul culorii curente testate: %d\n", c);
	puts("Apasa o tasta");
	getch();
	setgraphmode(mod);
	mira();
}