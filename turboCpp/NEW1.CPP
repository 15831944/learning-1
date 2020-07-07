/* handler pt alocare de memorie */
#include <iostream.h>
#include <stdlib.h>
#include <new.h>
void no_mem();
void main()
{
	int *ip;
	long dim;
	set_new_handler(&no_mem);
	cout<<"Dimensiune bloc ?";
	cin >> dim;
	for(int i=1;; i++) {
		ip = new int[dim];
		cout <<"Alocare bloc i = ";
		cout << i << "\n";
	}
}
void no_mem()
{
	cout << "Alocare imposibila\n";
	exit(1);
}