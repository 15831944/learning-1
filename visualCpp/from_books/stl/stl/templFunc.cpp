#include <afx.h>
#include <iostream>
using namespace std;
template <class T> void SchArg(T& foo, T& bar) {
	T temp;
	temp = foo;
	foo = bar;
	bar = temp;
}

int main() {
	CString szMsjFirst("Hi!");
	CString szMsjSecond("GoodBye!");
	cout << szMsjFirst << endl << szMsjSecond << endl;
	SchArg(szMsjFirst, szMsjSecond);
	cout << szMsjFirst << endl << szMsjSecond << endl;
	return EXIT_SUCCESS;
}