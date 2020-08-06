/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 *
 */
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
/* servicii ale intreruperii 0x33
 * 0 - reseteaza parametrii de stare ai mousului ax = 0 ax -> 1 instalat
 * 1 - aprinde cursolul mouse-ului ax = 1
 * 2 - stinge cursorul mousului ax = 2
 * 3 - determina starea butonului ax = 3, bx -> stare, cx -> poz X, dx -> poz Y
 * 4 - pozitioneaza cursul la o coordonata ax = 4,cx = x, dx = y
 * 5 - obtine inf privind apasare ax = 5, bx = 0/1 st/dr, ax -> stare,
 * bx -> numar buton, cx -> x, dx -> y
 * 6 - obtine inf privind relaxarea unui buton ax = 6, bx = nr buton,
 * ax -> stare buton, cx -> x, dx -> y
 * 7 - pozitioneaza limitele orizontale ax = 7, cx = limita min, dx = limita max
 * 8 - pozitioneaza limitele verticale ax = 8, cx = limita min, dx = limita max
 * 9 - modifica forma (grafic) ax = 9, bx = poz rel fata de poz curenta x,
 * cx = pozitia rel fata de poz curenta y, dx = pointer la masca cursorului
 * 10 - modica forma (alfa) ax = 10, bx = 0/1 soft/hard, cx = masca ecran (bx =0)
 * sau inceput linie scan (bx = 1), dx = marca cursor (bx=1) sau sfirsit
 * linie scan (bx = 1)
 */
/*
 * variabila init_mouse=1 daca mouse-ul a fost instalat, 0 altfel ,
 * iar in cazul cind mouse-ul este stins variabila m_deschis=0 altfel 1
 */
int init_mouse, m_desch;
/*
 * testul de init mouse-ul se face controlind adresa int 0x33
 * daca este NULL mouse nu este instalat
 */
int control_mdriv(int m)
{
	void far *adresa;
	adresa=getvect(0x33);
	if ((adresa == NULL) || (* (unsigned char*)adresa == 0xcf))
		if (m) {
			printf("\n Mouse neinstalat !!");
			exit(1);
		}
		else return 0;
	return 1;
}

/*
 * apelul propriu-zis al int 0x33 pentru difereite servicii este realizat
 * prin functia mouse, ai carei parametri transmisi prin adresa precizata
 * serviciile de executat, dupa care se primesc si returneaza rezultatele
 * intruperrii
 */
void mouse (int *ax, int *bx, int *cx, int *dx)
{
	union REGS inreg, outreg;
	inreg.x.ax = *ax;
	inreg.x.bx = *bx;
	inreg.x.cx = *cx;
	inreg.x.dx = *dx;
	int86(0x33, &inreg, &outreg);
	*ax = outreg.x.ax;
	*bx = outreg.x.bx;
	*cx = outreg.x.cx;
	*dx = outreg.x.dx;
}
/*
 * serviciile de: resetare parametri mouse, aprindere/stingere, mutare
 * cursor mouse sunt apelate prin functii distincte
 */
int reset_mouse()
{
	int m1,m2,m3,m4;
	m1 = 0;
	mouse(&m1,&m2,&m3,&m4);
	return m1;
}
void show_mouse()
{
	int m1,m2,m3,m4;
	if(init_mouse && !m_desch)
	{
		m1 = 1;
		mouse(&m1,&m2,&m3,&m4);
		m_desch = 1;
	}
}
void hide_mouse()
{
	int m1,m2,m3,m4;
	if (init_mouse && m_desch)
	{
		m1 = 2;
		mouse(&m1,&m2,&m3,&m4);
		m_desch = 0;
	}
}
void muta_mouse(int lin, int col)
{
	int m1,m2;
	if(!init_mouse)
		return;
	m1 = 4;
	mouse(&m1,&m2,&lin,&col);
}
/*
 * folosirea efectiva a mouse-ului se bazeaza pe citirea starii butoanelor
 * acestuia fie ca se face individual sau pe ansamblu
 */
int buton_apasatr()
{
	int m1,m2,m3,m4;
	if (init_mouse)
	{
		m1 = 5;
		m2 = 1;
		mouse(&m1,&m2,&m3,&m4);
		if (m1 == 2)
			return 1;
	}
	return 0;
}
int buton_apasatl()
{
	int m1,m2,m3,m4;
	if (init_mouse)
	{
		m1 = 5;
		m2 = 0;
		mouse(&m1,&m2,&m3,&m4);
		if (m1 == 1)
			return 1;
	}
	return 0;
}
int buton_stare()
{
	int m1,m2,m3,m4;
	if (init_mouse)
	{
		m1 = 3;
		mouse(&m1,&m2,&m3,&m4);
		return m2;
	}
	return 0;
}
/*
 * coordonatele de pe ecran la care se afla la un moment dat cussorul
 * pot fi citite.
 * coodonatele se dau in pixeli
 */
void obtine_coordon(int *lin, int *col)
{
	int m1,m2;
	if(init_mouse)
	{
		m1 = 3;
		mouse(&m1,&m2,lin,col);
	}
}
