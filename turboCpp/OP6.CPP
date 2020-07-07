/*
 * suprascrierea operatorilor unari ++ --
 */
#include <iostream.h>
class pozitie {
	int x,y; // coordante
public:
	pozitie(int abs=0,int ord=0) //constructor
	{
		x = abs;
		y = ord;
	}
	void afisare()
	{
		cout<<" x="<<x;
		cout<<",y="<<y<<'\n';
	}
	pozitie operator++()
	{
		x++;
		y++;
		cout<<"Op++ ";
		return pozitie(x,y);
	}
	pozitie operator--()
	{
		x--;
		y--;
		cout<<"Op-- ";
		return pozitie(x,y);
	}
};
void main()
{
	pozitie p(1,1), r;
	r = p++;
	r.afisare();
	r=--p;
	r.afisare();
	r = ++p;
	r.afisare();
	r = p--;
	r.afisare();
}