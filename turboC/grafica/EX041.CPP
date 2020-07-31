/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * moveto
 * muta pozitia cursorului grafic la punctul dat de coordonatele
 * (x,y)
 * daca anterior a fost definita o fereastra utilizind setviewport,
 * atunci valorile x, y se aduna la coordonatele coltului stinga sus
 * ale ferestrei si acest valori vor fi noile  coordonate ale cursorului
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* muta pozitia curenta la locatia (20,30) */
	moveto(20,30);
	putpixel(getx(),gety(), getmaxcolor());
	sprintf(msg," (%d,%d)", getx(), gety());
	outtextxy(20,30,msg);
	moveto(100,100);
	putpixel(getx(),gety(), getmaxcolor());
	sprintf(msg," (%d,%d)", getx(),gety());
	outtext(msg);
	getch();
	closegraph();
	return 0;
}