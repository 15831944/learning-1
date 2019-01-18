#include<stdio.h>
void func()
{
	printf("->Sunt in fucntie\n");
}
main()
{
	void func();
	strcpy((char *)func,"reziduu");
	printf("adresa fucntiei=%04x\n",func);
	func();
	printf("<-Am revenit din functie\n");
}