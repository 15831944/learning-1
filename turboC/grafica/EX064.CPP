/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * intalluserfont
 * incarca un fisier de fonturi .CHR care nu este construit
 * intr-un sistem BGI
 * se instaleaza seturi de caractere grafice utilizator
 * ea intoarce numarul tipului de caracter corespunzator
 * setului de caractere instalate. Daca tabela tipurilor de carctere
 * s-a umplut, valoarea intoarsa va fi 0
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void checkerrors(void);
int main(void)
{
	int gdriver = DETECT, gmode;
	int userfont;
	int midx, midy;
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	checkerrors();
	/* instaleaza un fisier de fonturi definit de utilizator */
	userfont = installuserfont("EURO.CHR");
	checkerrors();
	/* selecteaza fontul utilizator */
	settextstyle(userfont, HORIZ_DIR,4);
	outtextxy(midx,midy, "Testare!");
	getch();
	closegraph();
	return 0;
}

void checkerrors(void)
{
	int errorcode;
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
}
