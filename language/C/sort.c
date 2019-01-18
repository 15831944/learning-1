#include<stdio.h>
#include<stdlib.h>
void bubble(int *sir,int contor)
{
int i,j,temp;
	for(i=1;i<contor;i++)
	for(j=contor-1;j>=i;j--)
	{
		if(sir[j-1]>sir[j])
		{
			temp=sir[j-1];
			sir[j-1]=sir[j];
			sir[j]=temp;
		}
	}
}
void sel(int *sir,int contor)
{
int i,j,k;
int temp1,temp;
	for(i=0;i<contor-1;i++)
	{
		k=i;
		temp1=0;
		temp=sir[k];
		for(j=i+1;j<contor;j++)
		{
			if(sir[j]<temp)
			{
				k=j;
				temp=sir[k];
				temp1=1;
			}
		}
		if(temp1==1)
		{
			sir[k]=sir[i];
			sir[i]=temp;
		}
	}
}
				
void ins(int *sir,int contor)
{
int i,j;
int temp;
	for(i=1;i<contor;i++)
	{
		temp=sir[i];
		for(j=i-1;j>=0&&temp<sir[j];j--)
		{
			sir[j+1]=sir[j];
			sir[j]=temp;
		}
	}
}

int main(void)
{
int *sir1;
int nr,i;
	printf("\nintroduceti nr de elem nr=");fflush(stdout);
	scanf("%d",&nr);fflush(stdin);
	sir1=(int *)calloc(nr,sizeof(int));
	for(i=0;i<nr;i++)
	{
		printf("\nelem %d=",i);fflush(stdout);
		scanf("%d",&sir1[i]);fflush(stdin);
	}
	ins(sir1,nr);
	printf("elementele ordonate sunt\n");fflush(stdout);
	for(i=0;i<nr;++i)
	{
		printf("%d=%d\n",i,sir1[i]);fflush(stdout);
	}
	free(sir1);
	exit(0);
}