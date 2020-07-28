/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * detectgraph()
 * verifica hardwarul si determina si modul grafic care se poate folosi
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
/* Nume dediferite placi grafice suportate */
char *dname[] = { "requests detection", "CGA", "MCGA","EGA",
	"64K EGA","monochrome EGA", "IBM 8514", "Hercules monochrome",
	"AT&T 6300 PC", "VGA", "IBM 3270 PC"};
int main(void)
{
	int gdriver, gmode, errorcode;
	detectgraph(&gdriver,&gmode);
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);
	}
	/* afisarea informatiei detectate */
	clrscr();
	printf("Tu ai un display video cu o placa %s\n",dname[gdriver]);
	printf("Apasa orice tasta pentru oprire:");
	getch();
	return 0;
}