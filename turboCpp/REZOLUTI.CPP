/* operatorul de rezolutie */
#include <iostream.h>
char str[20] = "Sir global";
void fct()
{
	char *str; //variabila locala
	str = "Sir local";
	cout<<::str<<'\n'; //afiseaza sirul global
	cout << str<<'\n'; //afiseaza sirul local
}
void main()
{
	fct();
}