/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * arc
 * deseneaza conturul unui arc de cerc, in sens trigonometric
 * intre unghiurile de inceput si sfirsit pe un cerc cu centrul
 * si raza date
 * Daca unchiul de inceput este 0 si unghiul de sfirsit este 359
 * va desena un cerc complet
 * dupa apel cursorul va fi in centrul cercului
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int stangle = 45, endangle=135;
	int radius = 100;
	initgraph(&gdriver, &gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* deseneaza un sfert de cerc, situat in primul cadran al cercului
		de centru (100,100) si raza 50
	*/
	arc(midx,midy,stangle,endangle,radius);
	getch();
	closegraph();
	return 0;
}