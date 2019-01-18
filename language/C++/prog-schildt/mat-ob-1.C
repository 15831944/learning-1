#include<iostream.h>

class c1
{
	int i;
public:
	void pune_i(int j) {i=j;}
	int da_i() {return i;}
};

int main()
{
	c1 ob[3];
	int i;
	for(i=0;i<3;i++) ob[i].pune_i(i+1);
	for(i=0;i<3;i++) cout<<ob[i].da_i()<<"\n";
}