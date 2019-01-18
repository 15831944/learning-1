//Ex 4 de la pag 38
#include<iostream.h>
#include<alloc.h>
void main(void)
{
float **matrice;
float *pdata;
int i,j,contor;
int lin,col;
	cout<<"Introduceti linii si coloane\n";
	cin>>lin>>col;
	pdata=(float *)calloc(lin*col,sizeof(float));
	matrice=(float **)calloc(lin,sizeof(float *));
	for(i=0;i<lin;i++)
	{
		matrice[i]=pdata;
		pdata+=col;
	}
	cout<<"Introduceti datele\n";
	for(i=0;i<lin;i++)
	for(j=0;j<col;j++)
	{
		cout<<"x="<<i<<" "<<"y="<<j<<" ";
		cin>>matrice[i][j];
	}
	contor=0;
	for(i=0;i<lin;i++)
	for(j=0;j<col;j++)
	{
		if(matrice[i][j]==0) contor++;
	}
	if(contor>(lin*col*2/3-1)) cout<<"Matricea este rara";
	free(*matrice);
	free(matrice);
}