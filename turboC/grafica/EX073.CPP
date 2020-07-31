/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setactivepage
 * seteaza pagina activa pentru iesirea grafica
 * pe ecran este viziualizata o singura pagina grafica la un moment
 * dat. Functiile grafice vor scrie iesirea in pagina activa definita
 * de functia setactivepage
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = EGA, gmode = EGAHI, errorcode;
	int x,y, ht;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	x = getmaxx()/2;
	y = getmaxy()/2;
	ht = textheight("W");
	/* selectarea paginii eracn pentru desenare */
	setactivepage(1);
	/* desenarea unei linii pe pagina #1 */
	line(0,0,getmaxx(),getmaxy());
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(x,y,"Aceasta este pagina #1:");
	outtextxy(x,y+ht,"Apasa orice tasta pentru oprire:");
	/* selectare pagina #0 penru desenare */
	setactivepage(0);
	outtextxy(x,y,"Aceasta este pagina #0.");
	outtextxy(x,y+ht,"Apasa orice tasta pentru vizualizarea paginii #1:");
	getch();
	/* selectarea paginii #1 pentru a o face vizibila */
	setvisualpage(1);
	getch();
	closegraph();
	return 0;
}
