/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setusercharsize
 * modifica factorul de marine a caracterului definit de utilizator
 * pentru fonturilor stroked (vectoriale)
 * pentru ca sa functioneze dimensiunea caracterelor, trebuie ca
 * argumentul charsize al functiei settextstyle sa fie 0
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	moveto(0, getmaxy()/2);
	outtext("Normal ");
	/* produce textul de 1/3 din latimea normala */
	setusercharsize(1,3,1,1);
	outtext("Short ");
	setusercharsize(3,1,1,1);
	outtext("Wide");
	getch();
	closegraph();
	return 0;
}