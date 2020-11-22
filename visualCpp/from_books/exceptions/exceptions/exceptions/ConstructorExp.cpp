// exemplu de lansare a unei exceptii in interiorul unui constructor
#include <iostream>
#include <eh.h>

using namespace std;

class LocalGuy {
public:
	LocalGuy() {
		cout << "In constructorul LocalGuy." << endl;
	}
	~LocalGuy() {
		cout << "In destructorul LocalGuy." << endl;
	}
};

class Base {
public:
	Base() {
		cout << "In constructorul Base." << endl;
	}
	virtual ~Base() {
		cout << "In destructorul Base." << endl;
	}
};

class Derived : public Base {
public:
	Derived(int flag) {
		LocalGuy MyLocalGuy;
		cout << "In constructorul Derived." << endl;
		if (flag)
			throw - 1;
	}
	virtual ~Derived() {
		cout << "In destructorul Derived." << endl;
	}
};

int main() {
	try {
		Derived(1);
	}
	catch (int value) {
		cout << "A fost interceptata o exceptie Derived de valoare "<<value<<endl;
	}
}