/*
 * exemplu de apel grafic u mai multi parametrii
 */
#include <stdarg.h>
#include <conio.h>
#include <stdio.h>
int printxy(int xpoz, int ypoz,char *fmt, ...)
{
	va_list ap;
	int cnt;
	va_start(ap, fmt);
	gotoxy(xpoz,ypoz);
	cnt = vprintf(fmt, ap);
	va_end(ap);
	return cnt;
}

void main()
{
	printxy(25,12,"%8.2f",100.34);
}
