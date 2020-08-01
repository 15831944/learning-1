/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * programul care realizeaza incrcare unei imagini din fisierul IMAG.DAT
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <sys\stat.h>
#include <io.h>
#include <fcntl.h>
void restore_screen(void far *buf[4]);
void restore_mem(void far *buf[4]);
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
	restore_mem(ptr);
	maxx = getmaxx();
	maxy = getmaxy();
	setcolor(BLACK);
	restore_screen(ptr);
	getch();
	closegraph();
	return 0;
}
/* restaurarea imaginii din fisier in memorie */
void restore_mem(void far *buf[4])
{
	FILE *fp;
	int block;
	if ((fp = fopen("IMAG.DAT","rt")) == NULL)
	{
		printf("Nu se poate deschide fisierul IMAG.DAT in citire\n");
		exit(1);
	}
	fread(&marime,sizeof(unsigned),1,fp);
	for(block = 0; block <= 3; block++)
	{
		if((buf[block] = farmalloc(marime)) == NULL)
		{
			closegraph();
			printf("Eroare: nu este suficient spatiu heap in restore_mem.\n");
			exit(1);
		}
		fread((void *)buf[block],marime,1,fp);
	}
	fclose(fp);
}
/* restaurarea imaginii din memorie pe ecran */
void restore_screen(void far *buf[4])
{
	int ystart = 0, yend, yincr, block;
	yincr = (maxy + 1)/4;
	yend = yincr;
	for(block = 0; block <= 3; block++)
	{
		putimage(0,ystart,buf[block],COPY_PUT);
		farfree(buf[block]);
		ystart = yend +1;
		yend += yincr +1;
	}
}
