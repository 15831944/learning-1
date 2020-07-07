/*
 * function overloading
 */
#include <iostream.h>
void fct(int); //fct1
void fct(double); //fct2

void main()
{
	int i=5;
	float r =3.33;
	char c= 10;
	long l = 1000;
	fct(i); // apel fct1

	fct(r); // apel fct2 conversie float -> double
	fct(c); //apel fct1, conversie char -->int
//	fct(l) ;// eroare la compilare ambiguitate
}

void fct(int a)
{
	cout<<"fct1, argument=" << a<<"\n";
}
void fct(double a)
{
	cout<<"fct2, argument=" << a<<"\n";
}