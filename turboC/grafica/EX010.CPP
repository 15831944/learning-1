/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Determina gama modurilor grafice pentru driverul dat
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	/* autodetectie cerere */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int low, hight;
	char mrange[80];
	/* initializare grafica si a variabilelor locale */
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	getmoderange(gdriver,&low,&hight);
	/* converteste informatia despre gama modului in siruri */
	sprintf(mrange,"Acest driver suporta modurile %d..%d", low, hight);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy,mrange);
	getch();
	closegraph();
	return 0;
}