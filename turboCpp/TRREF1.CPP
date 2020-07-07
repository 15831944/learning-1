/*
 * transferul prin referinta
 */
#include <iostream.h>
void schimba (int &, int &);
void main()
{
	int i,j;
	cin >> i >> j;
	schimba(i,j);
	cout << i << ' ' << j;
}
void schimba(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}