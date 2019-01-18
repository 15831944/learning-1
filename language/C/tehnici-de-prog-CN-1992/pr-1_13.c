#include<stdio.h>
void hanoi(char a,char b,char c,int n)
{
	if(n==1) printf("Se muta de pe discul %c pe discul %c\n",a,b);
	else
	{
		hanoi(a,c,b,n-1);
		printf("Se muta de pe discul %c pe discul %c\n",a,b);
		hanoi(c,b,a,n-1);
	}
}
main()
{
	hanoi('A','B','C',3);
}