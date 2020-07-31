/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * bar3d
 * deseneaza un paralelipiped dreptunghic cu contur si hasureaza
 * fata sa cu modelul curent si culoarea curenta
 * pentru hasurare se vor folosi modelul si culoarea date de setfillstyle
 * sau setfillpattern
 * tipul si culoare liniei folosite pentru desenarea conturului sunt
 * determinate de setlunestyle si setcolor
 * dupa apel cursorul grafic va fi plasat in coltul dreapta sus din spate
 * al paralelipipedului desent
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy, i;
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
	/* bucla pentru modele hasurate */
	for(i = EMPTY_FILL; i < USER_FILL; i++)
	{
		setfillstyle(i, getmaxcolor());
		bar3d(midx-50,midy-50,midx+50,midy+50,10,1);
		getch();
	}
	closegraph();
	return 0;
}