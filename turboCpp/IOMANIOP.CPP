/*
 * io manipulatori
 */
#include <iomanip.h>
void main()
{
	int i = 127;
	cout<<i<<'='<<setiosflags(ios::showbase | ios::hex)<<i<<endl;
	double r1 = 123.456789;
	cout<<setw(12)<<r1<<endl<<r1<<endl;
	cout<<setprecision(4)<<r1<<endl;
	cout<<setiosflags(ios::scientific)<<r1<<endl;
}