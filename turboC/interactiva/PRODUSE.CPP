/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * program de teste pentru create unui fisier de produse
 */
#include <stdio.h>
#include <ctype.h>
#include <bios.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define KMAX 6
#define NC 10
struct articol
{
	int cod;
	char den[16];
	char um[4];
	float pret;
	float progr;
	float realiz;
	float contr[10];
	float livr[10];
	float rest[7];
};
#include "mach.cpp"
void main()
{
	FILE *pf;
	struct articol art;
	int cont = 1, nr =1;
	union zona { int a; char c[2]; } z;
	pf = fopen("prod.dat","w+b");
	textbackground(BLACK);
	clrscr();
	textcolor(YELLOW);
	textbackground(BLACK);
	desenm();
	fill(1);
	textcolor(GREEN);
	textbackground(YELLOW);
	scrnrart(nr);
	do
	{
		z.a = bioskey(0);
		if(z.c[0] != '\0')
			switch(z.c[0])
			{
				case '\b':
					left();
					del();
					break;
				case '\r':
					cr(&nr,&art,pf);
					break;
				case '\x1A':
					break;
				default:
					if(isgraph(z.c[0]) || ' ')
					{
						if(mach.k == 0 || mach.k == NC)
							if(!isdigit(z.c[0]))
							{
								printf("\a");
								continue;
							}
						if(cont)
							overwrite(z.c[0]);
						else
							insert(z.c[0]);
					}
					else
						printf("\a");
			}
		else
			switch(z.c[1])
			{
				case '\x48':
					up();
					break;
				case '\x50':
					down();
					break;
				case '\x4b':
					left();
					break;
				case '\x4d':
					right();
					break;
				case '\x52':
					ins(&cont);
					break;
				case '\x53':
					del();
					break;
				default:
					printf("\a");
			}
	} while(z.c[0] != '\x1A');
	fclose(pf);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
}