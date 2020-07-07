/*
 * testfifo.cpp
 * programul demonstrativ pentru clasa fifo
 */

#include "fifo.h"
#include <iostream.h>
void fct(int); // functie de test
fifo ls(10); // obiect global fifo (static)
void main()
{
	cout<<"Incepe main()\n";
	fifo la; // la este obiect automatic
	fifo *lp; //lp este pointer catre un obiect fifo
	lp = new fifo(20); // creare obiect dinamic
	fct(20);
	fct(40);
	delete lp;
	cout<<"Final main()\n";
}
void fct(int i)
{
	cout<<"Incepe fct("<<i<<")\n";
	fifo lf(i);
	cout<<"Final fct("<<i<<")\n";
}