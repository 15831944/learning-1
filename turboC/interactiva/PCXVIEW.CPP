/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * pcx viewer
 */
#include <stdio.h>
#include <process.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
struct ant
{
	unsigned char cod;
	unsigned char vers;
	unsigned char compr;
	unsigned char btperpixel;
	unsigned int x1,y1,x2,y2;
	unsigned int rezx, rezy;
	unsigned char paleta[48];
	unsigned char rezervat,plane;
	unsigned int octpelin,q;
	unsigned char rez[58];
} antet;
void main(int argc, char *argv[])
{
	FILE *fisier;
	unsigned int val1[10] = {
			0x6d,0x59,0x5a, 0x8e,0x62,0x8b,0x0b,0x3e,0x00,0x40};
	unsigned int val2[8] = {
			0xea, 0x8c, 0xdf,0x2d,0x01, 0xe7,0x04,0xc3};
	unsigned int w, act;
	unsigned char z[2500], bt;
	char far *inceput_ecran;
	union REGS regs;
	int i,j,i1,j1,k,t,x,y,dx,dy;
	if (argc != 2)
	{
		/*  test de apel indicind numele fisierului de vizualizat */
		printf("APEL : PCXVIEW fisier.pcx");
		exit(1);
	}
	if ((fisier = fopen(argv[1],"rb")) == NULL)
	{
		printf("\n fisierul %s nu poate fi deschis",argv[1]);
		exit(2);
	}
	if(fread(&antet,128,1,fisier) != 1 || antet.cod != 10)
	{
		/* citerea informatii privind structura frafia a fisierului */
		printf("\nAntetul nu poate fi citit !");
		exit(3);
	}
	fflush(stdin);
	printf(" \nCod : %d ",antet.cod);
	printf("\nVersiune : %d ",antet.vers);
	printf("\nComprim. : %d ",antet.compr);
	printf("\nBiti/pixel: %d ",antet.btperpixel);
	printf("\nx1=%d y1=%d x2=%d y2=%d ", antet.x1,antet.y1,antet.x2,antet.y2);
	printf("\nPlane : %d ", antet.plane);
	printf("\nOcteti pe linie: %d ", antet.octpelin);
	dx = antet.x2 - antet.x1 + 1;
	dy = antet.y2 - antet.y1 + 1;
	regs.x.ax = 0x13;
	int86(0x10,&regs,&regs);
	/* intrare in odul 0x13 VGA */
	outpw(0x03c4,0x604);
	outpw(0x03c4,0x100);
	outp(0x03c4,0xc7);
	outpw(0x03c4,300);
	outp(0x03c4,0x11);
	k = inp(0x03d5);
	k &= 0x7f;
	outp(0x03d5,k);
	outp(0x03d5, k);
	for(i=0; i<9; i++)
	{
		outp(0x03d4,i);
		outp(0x03d5,val1[i]);
	}
	for(i=0;i<8;i++)
	{
		outp(0x3d4,(i+0x10));
		outp(0x3d5,val2[i]);
	}
	outpw(0x3c4, 0xf02);
	inceput_ecran = (char far *)0xA0000000;
	for(i=1;i<=480*90;i++)
		inceput_ecran[i]='\xff';
	/* initializare memorie video */
	y = 0;
	act = 0;
	while(y < dy && !feof(fisier))
	{
	/* citire si vizualizare imagine */
		bt = getc(fisier);
		w - 1;
		if( bt >= 192)
		{
			w = bt - 192;
			bt = getc(fisier);
		}
		for(x = 1; x <= w; x++)
		{
			z[act] = bt;
			act++;
		}
		if(act >= dx)
		{
			for(i=1;i<=dx;i++)
			{
				k = i &3;
				i1 = y;
				j1 = i/4;
				outp(0x03c4,0x02);
				outp(0x3c5, (0x01 << k));
				/* sleectie plane de biti */
				inceput_ecran[i1*90 + j1] = z[i];
			}
			/* vizualizare prin inscriere in memoria video */
			act = 0;
			y++;
		}
	}
	fclose(fisier);
	printf("\n");
	getch();
	/* se asaptea pentru apasarea unei taste */
	regs.h.ah = 0x00;
	regs.h.al = 0x03;
	int86(0x10,&regs,&regs);
	/* revine in modul 0x03 */
}