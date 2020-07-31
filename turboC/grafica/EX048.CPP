/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * bar
 * deseneaza un dreptunghi fara contur hasurat cu modelul
 * curent si culoarea curenta
 * pozitia cursorului grafic nu este modificata
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy, i;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Erorare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* bucla in functie de modelul de hasurare */
	for (i = SOLID_FILL; i < USER_FILL; i++)
	{
		setfillstyle(i, getmaxcolor());
		bar(midx-50,midy-50,midx+50,midy+50);
		getch();
	}
	closegraph();
	return 0;
}