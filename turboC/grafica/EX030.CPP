/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getmaxcolor
 * intoarce valoarea maxima ce poate fi folosita pentru culori
 */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	char colstr[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* determinina inrormatia de culoare si o converteste la un sir */
	sprintf(colstr,"Acest mode suporta culorile 0..%d",getmaxcolor());
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx, midy, colstr);
	getch();
	return 0;
}