/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * exemplu de utilizare mouse in modul grafic
 */
#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include "mouse.h"
#include <process.h>
#define zona(st,sus,dr,jos,cc,cl) \
		cc >st&& cc<dr&& cl>sus&&cl<jos
extern int init_mouse, m_desch;
int coord[]= {100,100,550,250};
void cursor(void *forma)
{
	union REGS inreg,outreg;
	struct SREGS sregs;
	inreg.x.ax = 9;
	inreg.x.bx = 0;
	inreg.x.cx =0;
	inreg.x.dx = FP_OFF(forma);
	sregs.es = FP_SEG(forma);
	int86x(0x33,&inreg,&outreg,&sregs);
}
int initializm(int m, void *pat1)
{
	int var;
	init_mouse = 0;
	if(control_mdriv(m))
	{
		var = reset_mouse();
		if(var)
		{
			init_mouse = 1;
			muta_mouse(150,200);
			cursor((int *)pat1);
			show_mouse();
		}
		else if(m)
		{
			printf("\n ERR activ mouse!!!");
			getch();
			exit(1);
		}
	}
	return init_mouse;
}
void main()
{
	int m,mc,ml,d = DETECT;
	unsigned int pat1[] = {
	//masca negata
		0x0000, 0x0001, 0x0003, 0x0007,
		0x000f, 0x001f, 0x003f, 0x007f,
		0x0007, 0x0107, 0x0307, 0x071f,
		0x0f1f, 0x1fff, 0x3fff, 0x7fff,
	//masca cursor
		0xffff, 0xfffe, 0xfffc, 0xfff8,
		0xfff0, 0xffe0, 0xffc0, 0xff80,
		0xfff8, 0xfef8, 0xfcf8, 0xf8e0,
		0xf0e0, 0xe000, 0xc000, 0x8000
	};
	unsigned int pat2[] = {
	//masca negata
		0xfe7f, 0xfe7f, 0xfe7f, 0xfe7f,
		0xfe7f, 0xfe7f, 0xfe7f, 0x0000,
		0x0000, 0xfe7f, 0xfe7f, 0xfe7f,
		0xfe7f, 0xfe7f, 0xfe7f, 0xfe7f,
	//masca cursor
		0x0180, 0x0180, 0x0180, 0x0180,
		0x0180, 0x0180, 0x0180, 0xffff,
		0xffff, 0x0180, 0x0180, 0x0180,
		0x0180, 0x0180, 0x0180, 0x0180
	};
	initgraph(&d,&m,"H:\\BORLANDC\\BGI");
	rectangle(coord[0],coord[1],coord[2],coord[3]);
	if(initializm(1,pat1))
		do
		{
			obtine_coordon(&mc,&ml);
			if(zona(coord[0], coord[1], coord[2], coord[3],mc, ml))
				cursor((int*)pat1);
			else
				cursor((int*)pat2);
			if(buton_apasatr())
				break;
			if (buton_stare() == 1)
			{
				obtine_coordon(&mc,&ml);
				if (zona(coord[0], coord[1], coord[2], coord[3], mc, ml))
					putpixel(mc-1,ml-1, YELLOW);
			}
		} while(1);
	hide_mouse();
	closegraph();
}