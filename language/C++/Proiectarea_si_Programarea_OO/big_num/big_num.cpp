// big_num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bigint.h"


int main(int argc, char* argv[])
{
	Cbigint bint1,bint2;
	for(int i=5;i<9;i++)
		bint1.putr(i);
	for(i=5;i<9;i++)
		bint2.putr(i);
	cout<<bint1<<"+"<<bint2<<"=";
	bint1+bint2;
	cout<<bint1<<"-"<<bint2<<"=";
	bint1-bint2;
	cout<<bint1;
	return 0;
}
