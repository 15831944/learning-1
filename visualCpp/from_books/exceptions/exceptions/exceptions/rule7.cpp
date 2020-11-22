#include <iostream>
#include<eh.h>

using namespace std;

void Func1(int flag) {
	try {
		cout << "In Func1.\n";
		if (flag)
			throw "Exceptie de tip string";
	}
	catch (int) {
		cout << "A fost interceptata o exceptie de tip intreg.\n";
	}
}

int main() {
	try {
		Func1(1);
	}
	catch (const char *str) {
		cout << " A fost interceptata o exceptie de tip string: " << str << endl;
	}
	catch (...) {
		cout << " A fost interceptata o exceptie neindentificata.\n";
	}
}