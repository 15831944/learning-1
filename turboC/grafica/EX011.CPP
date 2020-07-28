/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * Installuserdriver.
 * Instaleaza un dispozitiv driver al utilizatorului adaugindu-l
 * la tabela dispozitiv driver BGI
 * nu functioneaza decit cu un driver care nu apartine de borland
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int huge detectEGA(void);
void checkerrors(void);
int main(void)
{
	int gdriver, gmode;
	gdriver = installuserdriver("EGAVGA", detectEGA);
	/* trebuie fortata deschiderea de catre rutina de detectie */
	gdriver = DETECT;
	/* cauta pentru orice instalare erorile */
	checkerrors();
	initgraph(&gdriver,&gmode,  "H:\\borlandc\\bgi");
	checkerrors();
	line(0,0,getmaxx(),getmaxy());
	getch();
	closegraph();
	return 0;
}
/* detectarea placii EGA sau VGA */
int huge detectEGA(void)
{
	int driver, mode, sugmode = 0;
	detectgraph(&driver,&mode);
	if((driver == EGA) || (driver == VGA))
		return sugmode;/* returneaza numarul modului video */
	else
		return grError;
}
/* cauta toate erorile grafice si le raporteaza */
void checkerrors(void)
{
	int errorcode;
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		printf("Apasa orice tasta pentru oprire:");
		getch();
		exit(1);
	}
}