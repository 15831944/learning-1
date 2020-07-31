/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * gettextsettings
 * tipul, directia, marimea si pozitia de asezare a setului de caractere
 * sunt pozitionate cu functiile settextstyle si settextjustify.
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* numele fonturilor suportate */
char *font[] = {"DEFAULT_FONT","TRIPLEX_FONT", "SMALL_FONT",
	"SANS_SERIF_FONT", "GOTHIC_FONT"};
/* nume de directii suportate */
char *dir[] = {"HORIZ_DIR","VERT_DIR"};
/* alinierea unui text orizontal suportate */
char *hjust[] = {"LEFT_TEXT","CENTER_TEXT","RIGHT_TEXT"};
/* alinierea unui text vertical suportate */
char *vjust[] = {"BOTTOM_TEXT","CENTER_TEXT","TOP_TEXT"};

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct textsettingstype textinfo;
	int midx, midy, ht;
	char fontstr[80], dirstr[80], sizestr[80];
	char hjuststr[80], vjuststr[80];
	initgraph(&gdriver,&gmode,"H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	/* determinarea informatiiei despre setarea curenta a textului */
	gettextsettings(&textinfo);
	sprintf(fontstr,"%s este stilul textului.",font[textinfo.font]);
	sprintf(dirstr,"%s este directia textului.", dir[textinfo.charsize]);
	sprintf(hjuststr,"%s este aliniera orizontala.", hjust[textinfo.horiz]);
	sprintf(vjuststr,"%s este alinierea verticala.", vjust[textinfo.vert]);
	/* afisarea informatie */
	ht = textheight("W");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy,fontstr);
	outtextxy(midx,midy+2*ht,dirstr);
	outtextxy(midx,midy+4*ht,sizestr);
	outtextxy(midx,midy+6*ht,hjuststr);
	outtextxy(midx,midy+8*ht,vjuststr);
	getch();
	closegraph();
	return 0;
}