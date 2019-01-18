#include<iostream.h>

class baza
{
public:
	baza() {cout<<"Il construi la base\n";}
	~baza() {cout<<"Il destrui la base\n";}
};
class derivat:public baza
{
public:
	derivat() {cout<<"Il construi le derive\n";}
	~derivat() {cout<<"Il detrui le derive\n";}
};
int main()
{
	derivat ob;
}
	