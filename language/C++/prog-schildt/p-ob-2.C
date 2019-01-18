#include<iostream.h>

class c1
{
	int i;
public:
	c1() {i=0;}
	c1(int j) {i=j;}
	int da_i() {return i;}
};

int main()
{
	c1 ob[3]={1,2,3};
	c1 *p;
	int i;
	p=ob;	//il prendre le base de la matrice
	for(i=0;i<3;i++)
	{
		cout<<p->da_i()<<"\n";
		p++; //il indiche vers le prochain ob
	}
}