#include<iostream.h>
#include<stdio.h>
#include<string.h>

void adunsir(char *s1,char *s2);
void adunsir(char *s1,int i);

int main()
{
	char sir[80];
	strcpy(sir,"Va ");
	adunsir(sir,"salut");
	cout<<sir<<"\n";
	adunsir(sir,100);
	cout<<sir<<"\n";
}

//il concatene deux serie
void adunsir(char *s1,char *s2)
{
	strcat(s1,s2);
}
//il concatene une serie avec un int
void adunsir(char *s1,int i)
{
	char temp[80];
	sprintf(temp," %d",i);
	strcat(s1,temp);
}