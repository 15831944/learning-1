/* Program care realizeaza binomul lui newton */
#include<iostream.h>
#include<stdlib.h>
#include<math.h>

float factorial(int numar)
{
int i;
float factorial=1;
	if(numar==0) return 1;
	for(i=1;i<numar+1;i++) factorial*=i;
	return factorial;
}

int main(void)
{
int n,i;
float combinari,a;
	cout<<"\n Introduceti (x+a) la puterea n, intii a si apoi n.\n";
	cin>>a>>n;
	cout<<"x"<<n<<"+";
	for(i=1;i<n;i++)
	{
		combinari=factorial(n)/factorial(i)/factorial(n-i);
		cout<<combinari*pow(a,i)<<"x("<<n-i<<")+";
	}
	cout<<pow(a,n);
	exit(0);
}