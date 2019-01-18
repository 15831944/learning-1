#include<iostream.h>
void showflags();
int main()
{
	showflags();
	cout.setf(ios::right | ios::showpoint | ios::fixed);
	showflags();
}
void showflags()
{
	long f,i;
	int j;
	char numgen[15][12]=
	{
		"skipws",
		"left",
		"right",
		"internal",
		"dec",
		"oct",
		"hex",
		"showbase",
		"showpoint",
		"uppercase",
		"showpos",
		"scientific",
		"fixed",
		"unitbuf",
	};
	f=cout.flags();
	for(i=1,j=0;i<=0x2000;i=i<<1,j++)
		if(i&f) cout<<numgen[j]<<" il est acctive\n";
		else cout<<numgen[j]<<" il est desactive\n";
	cout<<"\n";
}