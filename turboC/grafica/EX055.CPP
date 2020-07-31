/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * pieslice
 * deseneza si hasureaza un sector de cerc cu centrul in punctul
 * de coordonate (x,y) cu unghiurile de inceput si de sfirsit date
 * daca unghiul de incepu este 0 si ungiul de final este 359 atunci
 * va desena si va hasura un cerc complet.
 * unghiurile trebuie date in sens invers arcelor de ceasornic,
 * 0 grade corespunde orei 3 iar 90 de grade orei 12
 * dupa apel cursorul grafic va fi plasat in centrul cercului
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int stangle = 45, endangle = 135, radius = 100;
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
	setfillstyle(EMPTY_FILL,getmaxcolor());
	pieslice(midx,midy,stangle,endangle,radius);
	getch();
	closegraph();
	return 0;
}