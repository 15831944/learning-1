/*
 * Drivere grafice torbo C++ DETECT 0, CGA 1, MCGA 2, EGA 3, EGA64 4,
 * EGAMONO 5, IBM8514 6, HERCMONO 7, ATT400 8, VGA 9, PC3270 10
 * Module grafice VGA : VGALO 0 640x200, VGAMED 1 640x350, VGAHI 2 640x480
 * driverele BORLANDC\BGI
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main(void)
{
	int driver = DETECT, mod;
	char numemod[40];
	/* initializeaza sistemul grafic */
	initgraph(&driver, &mod, "H:\\BORLANDC\\BGI");
	/* testeaza erorile */
	int ercod = graphresult();
	if (ercod != grOk)
		if (ercod == grFileNotFound) {
			/* cale incorecta */
			char cale[40];
			puts("Eroare (BGI), introduceti calea corecta:");
			gets(cale);
			driver = DETECT;
			initgraph(&driver, &mod, cale);
		}
		else {
			/* alta eroare */
			puts("Eroare in sistemului grafic:");
			puts(grapherrormsg(ercod));
			return;
		}
	/* afiseaza numele modului la coordonate 100,100 */
	sprintf(numemod, "Modul grafic curent este %s",getmodename(getgraphmode()));
	outtextxy(100,100,numemod);
	outtextxy(100,120, "Apasa o tasta");
	getch();
	/* restaurarea modului text */
	restorecrtmode();
	puts("Acum suntem in modul text");
	puts("Apasa o tasta");
	getch();
	/* revine in modul grafic */
	setgraphmode(getgraphmode());
	/* afiseaza mesajul final */
	outtextxy(100,140," Apasa o tasta pentru inchiderea modului grafic");
	getch();
	/* inchiderea modului grafic */
	closegraph();
	puts("Sfirsitul programului");
	getch();
}
