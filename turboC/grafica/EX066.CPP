/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * settextjustify
 * seteaza aliniera textului pentru modul grafic
 * valorile implicite ale paraemtrilor horiz si
 * vert sunt: LEFT_TEXT si TOP_TEXT
 * afecteaza iesirea textului cu outtext si outtextxy
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void xat(int x, int y);
/* setarie alinierii orizontale a textului */
char *hjust[] = { "LEFT_TEXT", "CENTER_TEXT", "RIGHT_TEXT"};
/* setarile alinierii verticale a textului */
char *vjust[] = { "LEFT_TEXT", "CENTER_TEXT", "RIGHT_TEXT"};
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy, hj, vj;
	char msg[80];
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* bucla prin itnermediul alinierrii textului */
	for (hj = LEFT_TEXT; hj <= RIGHT_TEXT; hj++)
		for(vj = LEFT_TEXT; vj <= RIGHT_TEXT; vj++)
		{
			cleardevice();
			settextjustify(hj,vj);
			sprintf(msg,"%s %s",hjust[hj],vjust[vj]);
			/* creare de fire incrucisate pe ecran */
			xat(midx,midy);
			outtextxy(midx, midy, msg);
			getch();
		}
	closegraph();
	return 0;
}
/* deseneaza cu x la (x,y) */
void xat(int x, int y)
{
	line(x-4,y,x+4,y);
	line(x,y-4,x,y+4);
}
