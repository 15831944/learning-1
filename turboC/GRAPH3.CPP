/*
 * Se traseaza un chenar al ferestrei implicite si apoi se creaza
 * succesiv doua ferestre in care se deseneaza chnarul a le vizualiza
 * in final se sterge continutul ferestrei 2 si se revine la intregul
 * ecran.
 */
#include <conio.h>
void border(void);
void main()
{
	clrscr();
	/* deseneaza chenarul ecranului */
	border();
	gotoxy(3,2);
	cputs("Aceasta este fereastra implicita (tot ecranul)");
	getch();
	/* creaza prima fereastra */
	window(10,5,30,20);
	/* deemeaza chenarul ferestrei */
	border();
	gotoxy(3,2);
	cputs("Prima fereastra");
	getch();
	/* creaza a doua fereastra */
	window(40,5,70,15);
	/* deseneaza chenarul ferestrei */
	border();
	gotoxy(3,2);
	cputs("A doua fereastra");
	getch();
	/* sterge ultima fereastra */
	clrscr();
	getch();
	cputs("Sint tot in fereastra 2 !");
	getch();
	/* revine la intregul ecran */
	window(1,1,80,25);
	clrscr();
	cputs("Revenire al fereastra implicita (tot ecranul)");
	getch();
}

void border(void)
{
	unsigned char v=186,o=205,ss=201,ds=187,sj=200,dj=188;
	struct text_info cw;
	int dx,dy, i;
	/* determina dimensiunea ferestrei */
	gettextinfo(&cw);
	/* latimea ferestrei */
	dx=cw.winright-cw.winleft + 1;
	/* inaltimea ferestrei */
	dy = cw.winbottom - cw.wintop + 1;
	/* traseaza marginea superioara */
	gotoxy(1,1);
	putch(ss); /* colt stinga sus */
	for(i = 2; i< dx; i++)
		putch(o);
	putch(ds); /* colt dreapta sus */
	/* traseaza marginea inferioara */
	gotoxy(1,dy);
	putch(sj); /* colt stinga jos */
	for(i = 2; i < dx; i++)
		putch(o);
	_wscroll = 0;
	putch(dj); /* colt dreaptas jos */
	_wscroll = 1;
	/* traseaza marginile stinga si drepta */
	for(i = 2; i < dy; i++) {
		gotoxy(1,i);
		putch(v);
		gotoxy(dx,i);
		putch(v);
	}
}