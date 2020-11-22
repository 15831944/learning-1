#include <iostream>
#include <eh.h>

using namespace std;

void Func1() {
	try {
		throw "Ceva nu merge bine!";
	}
	catch (const char *) {
		cout << "Prelucrari initiale...\n";
		throw;
	}
}

int main() {
	try {
		Func1();
	}
	catch (const char *) {
		cout << "Alte prelucrari...\n";
	}
}
