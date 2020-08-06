/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * exemplu de mouse in mod text
 */
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include "mouse.h"

extern int init_mouse,m_desch;
#define zona(st,sus,dr,jos,cl,cc) \
	cc >= st && cc <= dr && cl>=jos && cl <=sus

/*
 * cerere de initializare mouse
 * in caz de succes cursorul  este adus in pozitia (1,1) dupa care
 * este apris
 */
int initializm(int m)
{
	int var ;
	init_mouse = 0;
	if(control_mdriv(m))
	{
		var = reset_mouse();
		if (var)
		{
			init_mouse = 1;
			muta_mouse(1,1);
			show_mouse();
		}
		else if (m)
		{
			printf("\n ERR activ mouse !!");
			getch();
			exit(1);
		}
	}
	return init_mouse;
}
/* apasarea butonului drept duce la iesirea din program */
void main()
{
	char *pc[] = {"Zona1","Zona2","Zona3"};
	char *ps= "Actiunea din %s       ";
	int lg = 5;
	int lin[] = {4,7,4};
	int col[] = {11,24,36};
	int i, ml, mc, vb;
	textattr(0x07);
	clrscr();
	textattr(0x70);
	for(i =0; i < 3;i++)
	{
		gotoxy(col[i],lin[i]);
		cprintf("%s",pc[i]);
	}
	textattr(0x07);
	if (initializm(1))
	{
		do
		{
			if (buton_apasatr()) break;
			if (buton_stare() == 1)
			{
				obtine_coordon(&mc,&ml);
				for(i =0, vb = 0; i < 3; i++)
					if(zona(col[i],lin[i],col[i]+lg-1,lin[i],ml/8 +1, mc/8 +1))
					{
						gotoxy(31,20);
						cprintf(ps,pc[i]);
						vb =1;
						break;
					}
				if (!vb)
				{
					gotoxy(31,20);
					cprintf("Zona fara semnificatie!");
				}
			}
		} while(1);
	}
	hide_mouse();
}