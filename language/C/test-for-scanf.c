#include<stdio.h>
int main()
{
	char sir[10];
	int i;
	sir[9]='\n';
	for(i=0;i<9;i++)
	{
		scanf("%c",&sir[i]);
		fflush(stdin);
	}
	printf("%s\n",sir);
	fflush(stdout);
	{
	int j;
	j=10;
	printf("%d",j);
	}
}