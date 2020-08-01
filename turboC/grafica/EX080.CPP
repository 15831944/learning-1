/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * grapherrormsg
 * intoarce un pointer la un sir mesaj de eroare
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define NONSENSE -50
int main(void)
{
	/* forteaza o erare la intimplare */
	int gdriver = NONSENSE, gmode, errorcode;
	initgraph(&gdriver,&gmode,"h:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	line(0,0,getmaxx(),getmaxy());
	getch();
	closegraph();
	return 0;
}