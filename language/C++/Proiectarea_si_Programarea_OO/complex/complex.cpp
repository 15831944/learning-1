// complex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "complex1.h"
#include <iostream.h>


int main(int argc, char* argv[])
{
	Ccomplex op1,op2,op3,op4,op5;
	double temp;
	cin>>temp;
	op1.setreal(temp);
	cout<<"i ";cin>>temp;
	op1.setimag(temp);
	cin>>temp;
	op2.setreal(temp);
	cout<<"i ";cin>>temp;
	op2.setimag(temp);
	op3=op2+op1;
	op3.afiseaza();
	op4=op2*op1;
	op4.afiseaza();
	op5=op2^2;
	op5.afiseaza();
	return 0;
}
