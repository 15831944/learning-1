/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Exemplu de utilizare initgraph
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	/* cerere autodectie */
	int gdriver = DETECT, gmode, errorcode;
	/*initializarea modului grafic */
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	/* citirea rezultatului initializarii */
	errorcode = graphresult();
	if (errorcode != grOk) /* exista o eroare */
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1); /* intoarece un cod de eroare */
	}
	/* deseneaza o linie */
	line(0,0, getmaxx(),getmaxy());
	/* curatare completa */
	getch();
	closegraph();
	exit(0);
}