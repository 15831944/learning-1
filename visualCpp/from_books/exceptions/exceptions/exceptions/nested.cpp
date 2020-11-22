#include <stdlib.h>
#include <iostream>
#include <eh.h>

using namespace std;

//constante
const int MIN_FLAG_VALUE = 0;
const int MAX_FLAG_VALUE = 10;
const int FLAG_OUT_OF_BOUNDS = 0xFF;

//prelucrare
void DoSomethingElse() {
	cout << "In functia DoSomethingElse.\n";
}

void DoSomethingUseful(int Flag) {
	cout << "In functia DoSomethingUseful.\n";
	//variabila flag este prea mica sau prea mare
	if (Flag < MIN_FLAG_VALUE || Flag > MAX_FLAG_VALUE)
		throw FLAG_OUT_OF_BOUNDS;
	//operatii de prelucrare
	try {
		if (Flag == 0) {
			cout << "Flag este zero.\n";
			DoSomethingElse();
		}
		else {
			throw "Flag este diferit de zero.";
		}
	}
	catch (const char *ErrorString) {
		cout << ErrorString << endl;
		cout.flush();
	}
	catch (...) {
		cout << "Cought exceptie!" << endl;
	}
}

int main(int argc, char **argv) {
	//Daca in linia de comanda nu se primeste nici un argument atribuie valoarea zero variabilei Flag
	int UseFlag = (argc == 1 ? 0 : atoi(argv[1]));
	try {
		DoSomethingUseful(UseFlag);
	}
	catch (int ErrorCode) {
		cout << "A fost interceptata o exceptie (" << ErrorCode << ")\n";
	}
}