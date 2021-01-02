// inverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"matrix.h"
using namespace std;

int main(int argc, char* argv[])
{
	Cmatrix m1,m2,m3,m4,m5;
	long dim,i,j;
	double temp;
	cout<<"Input the matrix dimension dim=";cin>>dim;
	m1.setdim(dim);
//	m2.setdim(dim);
	cout<<"Input the first matrix\n";
	for(i=0;i<dim;i++)
		for(j=0;j<dim;j++)
		{
			cin>>temp;
			m1.set(temp,i,j);
		}
/*	cout<<"\n Input the second matrix\n";
	for(i=0;i<dim;i++)
		for(j=0;j<dim;j++)
		{
			cin>>temp;
			m2.set(temp,i,j);
		}
	m3=m1*m2;
	cout<<"Mult of the matrix\n";
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim;j++)
			cout<<m3.get(i,j)<<" ";
		cout<<endl;
	} */
	m4=m1.inv();
	m5=m1*m4;
	cout<<"resoult of the multiplication\n";
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim;j++)
			cout<<m5.get(i,j)<<" ";
		cout<<endl;
	}
	return 0;
}
