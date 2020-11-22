#include <iostream>
#include <eh.h>

using namespace std;

class Base {};
class Derived : public Base {};

void Func1(int flag) {
	cout << "In Func1.\n";
	if (flag)
		throw new Derived;
}

int main() {
	try {
		Func1(1);
	}
	catch (Derived*) {
		cout << "A fost interceptata o exceptie de tip Derived*.\n";
	}
	catch (Base*) {
		cout << "A fost interceptata o exceptie de tip Base*.\n";
	}
	catch (void *) {
		cout << "A fost incerceptata o exceptie de tip void*.\n";
	}
	catch (...) {
		cout << "A fost inteceptata o exceptie neidentificata.\n";
	}
}