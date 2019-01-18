#include<stdio.h>
#include<conio.h>
void main()
{
	char c;
	do
	{
		printf("\nIntroduceti o cifra:");
		c=getche();
	} while(c<'0'||c>'9');
	printf("\tCodul ASCII este: %x h=%d\n",c,c);
}
	