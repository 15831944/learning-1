#include<iostream.h>

void neg(int *i);
int main()
{
	int x;
	x=10;
	cout<<x<<" il est la negation de ";
	neg(&x);
	cout<<x<<"\n";
}
void neg(int *i)
{
	*i=-*i;
}