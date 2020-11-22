//functia template specializa pentru lucrul cu pointeri de tip caracter
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
unsigned int AddEquals(T val1, T val2, T compare) {
	return (val1 + val2) == compare;
}

//specializare pentru pointeri de tip caracter
unsigned int AddEquals(const char *val1, const char *val2, const char *compare) {
	char Temp[512];
	sprintf_s(Temp, "%s%s", val1, val2);
	return !strcmp(Temp, compare);
}

int main() {
	//legal - using template
	cout << "Does 4 +5 = 9? ";
	cout << (AddEquals(4, 5, 9) ? "Yes" : "No") << endl;

	//legal - using template
	cout << "Does 7.0 + 5.5 = 12.0? ";
	cout << (AddEquals(7.0, 5.5, 12.0) ? "Yes" : "No") << endl;

	//legal - using specialization
	cout << "Does \"Big \" + \"Dog\" = \"Big Dog\"? ";
	cout << (AddEquals("Big ", "Dog", "Big Dog") ? "Yes" : "No") << endl;
}