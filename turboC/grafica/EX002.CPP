/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Deseneaza  pe ecran un dreptunghi de marime maxima si
 * scrie un text orizontal si unul vertical in mijlocul lui
 */
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	/* cerere autodetectie */
	int graphdriver = DETECT;
	int graphmode;
	int errorcode;
	/* initializeaza mod grafic */
	initgraph(&graphdriver,&graphmode, "h:\\borlandc\\bgi");
	/* intoarce cod eroare */
	errorcode = graphresult();
	if (errorcode != grOk) /* exista eroare */
	{
		/* afisare mesaj */
		printf("Eroare grafica\n");
		/* intoarce mesaj eroare corespunzator codului */
		grapherrormsg(errorcode);
		/* afisare mesaj */
		printf("Apasa orice tasta pentru iesiere:\n");
		/* asteapta apasare o tasta */
		getch();
	}
	/* deseneaza un dreptunghi */
	rectangle(0,0,getmaxx(),getmaxy());
	/* setare aliniere text */
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	/* setare stil text */
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	/* iesire text */
	outtextxy(getmaxx()/2, getmaxy()/2,"Sistem grafic IBM");
	/* setare stil text */
	settextstyle(DEFAULT_FONT, VERT_DIR, 3);
	/* iesire text */
	outtextxy(getmaxx()/2, getmaxy()/2,"Un text vertical");
	/* asteptare apasare o tasta */
	getch();
	/*inchide mod grafic */
	closegraph();
}