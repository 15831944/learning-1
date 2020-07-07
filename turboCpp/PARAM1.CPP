/*
 * parametrii cu valori implicite
 */
#include <iostream.h>
void fct(int, int=10);
void main()
{
	cout << "apel:fct(5,99), ";
	fct(5,99); //apel normal
	cout << "apel:fct(5) , ";
	fct(5); // apel cu un singur argument
}
void fct(int i, int j)
{
	cout << " parametri: i= " << i;
	cout << " j= " << j << "\n";
}