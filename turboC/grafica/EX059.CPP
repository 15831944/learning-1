/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setaspectratio
 * seteaza aspectul dimensional grafic
 * in cazul in care cercul este torsionat, prin schimbarea raportului
 * dimensional cu functia setaspectratio acest lucru se poate corecta.
 * aspectul dimensional la utilizarea functiei arc si a functiilor
 * similare face ca cercurile sa devina rotunde nu ovale.
 * yasp = 10000, utilizati xasp = 10000 cind pixelii sunt patrati VGA
 * si < 10000 cind sunt inalti.
 * acest raport este necesar pentru rotunjirea desenelor realizate cu
 * circle, arc si pieslice
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int xasp, yasp, midx, midy;
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	setcolor(getmaxcolor());
	/* determinarea setarilor aspectului dimensional curent */
	getaspectratio(&xasp,&yasp);
	/* deseneaza un cerc normal*/
	circle(midx,midy,100);
	getch();
	cleardevice();
	/* ajustarea aspectului pentru un cerc intins (lat) */
	setaspectratio(xasp/2,yasp);
	circle(midx,midy,100);
	getch();
	/* ajustarea aspectului pentru in cerc ingust (strimpt) */
	setaspectratio(xasp,yasp/2);
	circle(midx,midy,100);
	getch();
	closegraph();
	return 0;
}