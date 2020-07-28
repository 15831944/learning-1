/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Sunt realizate cinci dreptunghiuri colorate (ferestre)
 * in care se inscriu diferite texte.
 */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
void main()
{
	int fnpg(int lin, int col);
	void scrtxt(int lin, int col, char sir[256]);
	void drawin(int wlin, int wcol, int dlin, int dcol, int culoare);
	int wlin, wcol, dlin, dcol, culoare, lin, col;
	char *sir;
	clrscr();

	wlin = 4;
	dlin = 1;
	dcol = 50;
	culoare = 27;
	wcol = 15;
	drawin(wlin,wcol, dlin, dcol, culoare);

	col = 19;
	lin = 4;
	sir = "Program exemplu de scriere in memoria video";
	scrtxt(lin, col, sir);

	wlin = 8;
	dlin = 1;
	dcol = 20;
	culoare = 23;
	wcol = 15;
	drawin(wlin, wcol, dlin, dcol, culoare);

	col = 20;
	lin = 8;
	sir = "Fructe";
	scrtxt(lin, col, sir);

	wlin = 10;
	dlin = 5;
	dcol = 20;
	culoare = 36;
	wcol = 15;
	drawin(wlin, wcol, dlin, dcol, culoare);

	col = 20;

	lin = 10; sir = "Mere"; scrtxt(lin, col, sir);
	lin = 11; sir = "Pere"; scrtxt(lin,col, sir);
	lin = 12; sir = "Cirese"; scrtxt(lin, col, sir);
	lin = 13; sir = "Visine"; scrtxt(lin, col, sir);
	lin = 14; sir = "Caise"; scrtxt(lin, col, sir);

	wcol = 45;
	drawin(wlin, wcol, dlin, dcol, culoare);

	wlin = 8;
	dlin = 1;
	dcol = 20;
	culoare = 23;
	wcol = 45;
	drawin(wlin, wcol, dlin, dcol, culoare);

	col = 50;
	lin = 8;
	sir = "Prajituri";
	scrtxt(lin, col, sir);

	col = 50;
	lin = 10; sir = "Ecleruri"; scrtxt(lin, col, sir);
	lin = 11; sir = "Fursecuri"; scrtxt(lin, col, sir);
	lin = 12; sir = "Amandine"; scrtxt(lin, col, sir);
	lin = 13; sir = "Savarine"; scrtxt(lin, col, sir);
	lin = 14; sir = "Tarte"; scrtxt(lin, col, sir);
	getch();
}
/*
 * Functie pentru dterminarea in memoria video a pozitiei de memorare
 * a caracterului din linia lin si coloana col a ecranului.
 */
int fnpg(int lin, int col)
{
	return (lin * 80 + col)*2;
}
/*
 * Functie pentru desenarea unei ferestre colorate
 */
void drawin(int wlin, int wcol, int dlin, int dcol, int culoare)
{
	int x,y;
	for (x = wlin; x < wlin + dlin; x++)
		for(y = wcol; y < wcol + dcol; y++)
			poke(0xB800, fnpg(x,y) + 1, culoare);
}
/*
 * Functie pentru scrierea unui text din linia lin si coloana col
 */
void scrtxt(int lin, int col, char sir[])
{
	int i;
	for(i = 0; i <= strlen(sir); i++)
		pokeb(0xB800, fnpg(lin, col + i), sir[i]);
}