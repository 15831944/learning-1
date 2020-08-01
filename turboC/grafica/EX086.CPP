/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setgraphbufsize
 * schimba dimensiunea bufferului intern grafic
 * buferul implicit are 4k suficient pentru a umplu cu o culoare un
 * poligon cu 655 virfuri
 * trebuie apelata inainte de initgraph daca este apelata dupa este
 * ignorata pina la un nou apel initgraph
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#define BUFSIZE 1000
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int x,y, oldsize;
	char msg[80];
	oldsize = setgraphbufsize(BUFSIZE);
	clrscr();
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	x = getmaxx() /2;
	y = getmaxy()/2;
	sprintf(msg, "Dimensiunea bufferului grafic: %d", BUFSIZE);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x,y,msg);
	sprintf(msg,"Dimensiunea veche a bufferului grafic: %d",oldsize);
	outtextxy(x,y+textheight("W"),msg);
	getch();
	closegraph();
	return 0;
}