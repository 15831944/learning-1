/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setvisualpage
 * seteaza vizualizarea paginii grafice specificata prin numarul ei
 * pe ecran este vizualizata o singura pagina grafica la un moment dat
 * functiile grafice vor scrie iesire la pagina activa definita.
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = EGA, gmode = EGAHI, errorcode;
	int x,y, ht;
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	x = getmaxx()/2;
	y = getmaxy()/2;
	ht = textheight("W");
	/* selectarea paginii de pe ecran pentru desenare */
	setactivepage(1);
	/* desenarea pe pagina #1 */
	line(0,0,getmaxx(),getmaxy());
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x,y,"Aceasta este pagina #1:");
	outtextxy(x,y +ht,"Apasa orice tasta pentru oprire:");
	/* selectare desen la pagina #0 */
	setactivepage(0);
	outtextxy(x,y,"Aceasta este pagina #0.");
	outtextxy(x,y + ht,"Apasa orice tasta pentru vizualizarea paginii #1:");
	getch();
	setvisualpage(1);
	getch();
	closegraph();
	return 0;
}