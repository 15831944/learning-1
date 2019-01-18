#include<iostream.h>
int main()
{
	cout.setf(ios::right);
	cout<<"Este un test.\n";
	cout.unsetf(ios::right);
	//affiche hexa
	cout.setf(ios::showbase | ios::hex);
	cout<<100<<"\n";	//affiche 0x64
	cout.unsetf(ios::hex);
	cout.unsetf(ios::showbase);
	//affiche scientifique Grosse
	cout.setf(ios::uppercase | ios::scientific);
	cout<<100.12<<"\n";
	cout.unsetf(ios::uppercase);
	//affiche scientifique Pettite
	cout<<100.12<<"\n";
	cout.unsetf(ios::scientific);
	//affiche normale
	cout<<100.12<<"\n";
	//affiche acev point et signe
	cout.setf(ios::showpos | ios::showpoint);
	cout<<10.0<<" \n";
	cout.setf(ios::showpoint,ios::showpos | ios::showpoint);
	cout<<10.0<<" \n";
	cout.unsetf(ios::showpoint);
	//change de hex en oct
	cout.setf(ios::showbase | ios::hex);
	cout.unsetf(ios::dec);
	cout<<100<<"\n";
	cout.setf(ios::oct,ios::hex | ios::oct);
	cout<<100<<"\n";
	cout.unsetf(ios::oct);
	
	cout<<"\n";
}