/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * getimage
 * salveza imaginea bit dintr-o regiune specificata in memorie
 * regiunea specificata este o zona dreptunghiulara de pe ecran ce
 * contine imaginea cea va fi salvata intr-o zona tampon din memorie
 * primele doua cuvinte de memorie din zona tampon vor contine
 * latimea si lungimea zonei de forma dreptunghiulara ce se salveaza
 * asa ca zona tampon trebuie sa fie cu 4 octeti mai mare
 * dimensiunea necesara pentru salvare se poate obtine cu imagesize
 * ea nu poate sa depaseasca 64kocteti
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
void save_screen(void far *buf[4]);
void restore_screen(void far *buf[4]);
int maxx, maxy;
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	void far *ptr[4];
	initgraph(&gdriver,&gmode, "h:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();
	rectangle(0,0,maxx,maxy);
	line(0,0,maxx,maxy);
	line(0,maxy,maxx,0);
	save_screen(ptr);
	getch();
	cleardevice();
	getch();
	restore_screen(ptr);
	getch();
	closegraph();
	return 0;
}
/* functie de salvare a ecranului */
void save_screen(void far *buf[4])
{
	unsigned size;
	int ystart=0, yend, yincr,block;
	yincr = (maxy + 1)/4;
	yend = yincr;
	size = imagesize(0,ystart,maxx,yend);
	for (block =0; block <=3; block++)
	{
		if((buf[block] = farmalloc(size)) == NULL)
		{
			closegraph();
			printf("Eroare: nu exista suficient spatiu heap pentru salvarea ecranului.\n");
			exit(1);
		}
		getimage(0,ystart,maxx,yend,buf[block]);
		ystart = yend +1;
		yend +=yincr +1;
	}
}
void restore_screen(void far *buf[4])
{
	int ystart = 0, yend, yincr, block;
	yincr = (maxy+1)/4;
	yend = yincr;
	for(block = 0; block <=3; block++)
	{
		putimage(0,ystart,buf[block],COPY_PUT);
		farfree(buf[block]);
		ystart = yend + 1;
		yend += yincr + 1;
	}
}