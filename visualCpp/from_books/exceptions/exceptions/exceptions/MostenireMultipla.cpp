
#include <iostream>
#include <eh.h>
using namespace std;

class First1{};
class First2 {};
class Last :public First1, public First2 {};

Last MyLast;

void Func1(int flag) {
	cout << "In Func1" << endl;
	if (flag)
		throw MyLast;
}

int main() {
	try {
		Func1(1);
	}
	catch (First1&) {
		cout << "A fost interceptata o exceptie de tip First1.\n";
	}
	catch (First2&) {
		cout << "A fost interceptata o exceptie de tip First2.\n";
	}
	catch (...) {
		cout << "A fost interceptata o exceptie necunoscuta.\n";
	}
}