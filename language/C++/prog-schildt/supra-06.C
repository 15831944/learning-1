#include<iostream.h>
class loc
{
	int longitud,latitud;
public:
	loc() {}; //il este necessaire pour construire les teomporares
	loc(int lg,int lt)
	{
		longitud=lg;
		latitud=lt;
	}
	void arata()
	{
		cout<<longitud<<" "<<latitud<<"\n";
	}
	loc operator+(loc op2);
	loc operator-(loc op2);
	loc operator=(loc op2);
	loc operator++();
	loc operator++(int x);
	loc operator+=(loc op2);
};
loc loc::operator+(loc op2)
{
	loc temp;
	temp.longitud=op2.longitud+longitud;
	temp.latitud=op2.latitud+latitud;
	return temp;
}
loc loc::operator-(loc op2)
{
	loc temp;
	temp.longitud=longitud-op2.longitud;
	temp.latitud=latitud-op2.latitud;
	return temp;
}
loc loc::operator=(loc op2)
{
	longitud=op2.longitud;
	latitud=op2.latitud;
	return *this;
}
loc loc::operator++()
{
	longitud++;
	latitud++;
	return *this;
}
loc loc::operator++(int x)
{
 	loc temp;
 	temp.longitud=longitud;
 	temp.latitud=latitud;
	longitud++;
	latitud++;
	return temp;
}
loc loc::operator+=(loc op2)
{
	longitud=longitud+op2.longitud;
	latitud=latitud+op2.latitud;
	return *this;
}
int main()
{
	loc ob1(10,20),ob2(5,30),ob3(90,90);
	ob1.arata();
	ob2.arata();
	++ob1;
	ob1.arata();	//affiche 11 21
	ob2=++ob1;
	ob1.arata();	//affiche 12 22
	ob2.arata();	//affiche 12 22
	ob2=ob2+ob1++;
	ob1.arata();	//affiche 13 23
	ob2.arata();	//affiche 24 44
	ob1=ob2=ob3;	//atribuire multiple
	ob1.arata();	//affiche 90 90
	ob2.arata();	//affiche 90 90
	ob1+=ob2;
	ob1.arata();	//affiche 180 180
	ob2.arata();	//affiche 90 90
}