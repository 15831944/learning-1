/*
 * transfer prin referinta
 */
#include <iostream.h>
#include <conio.h>

void schimba(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
	cout <<"Functia schimba(): ";
	cout << "a= " << a << ",b= " << b<<'\n';
}
void main()
{
	int i =1, j=2;
	float p = 33.333, q = 44.444;
	clrscr();
	cout <<"Initial\n";
	cout << "i= " << i << ",j= "<< j << '\n';
	cout << "p= " << p;
	cout << ",q=" << q << '\n';
	schimba(i,j);
	schimba(p,q);
	cout <<"Final\n";
	cout << "i= " << i << ",j= "<< j << '\n';
	cout << "p= " << p << ",q=" << q << '\n';
}

