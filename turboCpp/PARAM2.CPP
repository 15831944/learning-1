/* parametrii cu valori implicite */
#include <iostream.h>
/* eroare de compilare
int fct1(char ='A',int, float=15);
*/
double fct2(int=5,double=3.5); //corect
void fct3(int, long=99,float=10.5); //corect
void main()
{
	float vf=1.5;
	fct3(0); //apel corect: i=0,j=99,r=10.5
	fct3(1,vf); //apel incorect i=1, j=1, r=10.5
	fct3(2,2.5); //apel incorect i=2, j=2, r=10.5
}

double fct2(int i, double d) // eroare compilare daca d=3.5
{
	cout << "i="<<i;
	cout << ",d="<<d<<'\n';
	return d;
}
void fct3(int i, long j, float r)
{
	cout << '\n';
	cout << "i=" << i;
	cout <<",j=" << j << ",r="<<r;
}