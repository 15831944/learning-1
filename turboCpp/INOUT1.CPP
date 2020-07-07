/*
 * utilizare operatiilor de intrare-iesire de la consola
 */
#include <iostream.h>
void main()
{
	int i;
	char nume[21];
	float r;
	cout << "Introduceti un numar intreg si apoi un numar real: ";
	cin >> i >> r;
	cout << "\nAti introdus: " <<i << " si " << r <<'\n';
	cout << "Introduceti numele dumneavoastra: ";
	cin >> nume;
	cout << "Salut, " << nume << " !\n";
}