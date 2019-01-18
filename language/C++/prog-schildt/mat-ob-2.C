#include<iostream.h>

class c1
{
	int i;
public:
	c1(int j) {i=j;} //constructeur
	int da_i() {return i;}
};
int main()
{
	c1 ob[3]={1,2,3}; //initialization
	int i;
	for(i=0;i<3;i++) cout<<ob[i].da_i()<<"\n";
}