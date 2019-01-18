#include<stdio.h>

void linii(int *mat,int n)
{
	int i,j;
	int *temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) printf("%d ",*(mat+j+i*n));
		printf("\n");
	}
}

void coloane(int *mat,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) printf("%d ",*(mat+n*j+i));
		printf("\n");
	}
}

int main()
{
	int mat[3][3];
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			mat[i][j]=j+i;
	linii(&mat[0][0],3);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}
	