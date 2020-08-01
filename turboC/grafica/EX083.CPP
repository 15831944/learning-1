/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * programul care realizeaza salvarea unei imagini in fisierul IMAG.DAT
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <sys\stat.h>
#include <io.h>
#include <fcntl.h>
void save_screen(void far *buf[4]);
void save_mem(void far *buf[4]);
int maxx, maxy;
unsigned marime;
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	void far *ptr[4];
	initgraph(&gdriver,&gmode,"h:\\borlandc\\bgi");
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
	save_screen(ptr); /* ecran -> memorie */
	save_mem(ptr); /* memorie -> file */
	getch();
	closegraph();
	return 0;
}
/* salvarea in memorie a ecranului curent */
void save_screen(void far *buf[4])
{
	int ystart = 0, yend, yincr, block;
	yincr = (maxy + 1)/3;
	yend = yincr;
	marime = imagesize(0, ystart, maxx, yend);
	for(block = 0; block <= 3; block ++)
	{
		if((buf[block] = farmalloc(marime)) == NULL)
		{
			closegraph();
			printf("Eroare: nu este suficient spatiu heap in save_screen.\n");
			exit(1);
		}
		getimage(0,ystart,maxx, yend, buf[block]);
		ystart = yend + 1;
		yend += yincr + 1;
	}
}
/* salvare intr-un fisier a imaginii din memorie */
void save_mem(void far *buf[4])
{
	FILE *fp;
	int block;
	if ((fp = fopen("IMAG.DAT","wt")) == NULL)
	{
		printf("Nu se poate deschide fisierul IMAG.DAT in creare\n");
		exit(1);
	}
	fwrite(&marime,sizeof(unsigned),1,fp);
	fflush(fp);
	for(block = 0; block <= 3; block++)
	{
		fwrite((void *)buf[block],marime,1,fp);
		fflush(fp);
	}
	fclose(fp);
}