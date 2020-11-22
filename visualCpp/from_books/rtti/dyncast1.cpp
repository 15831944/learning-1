#include <iostream>

using namespace std;

class Base {
	//do nothing is not polymorphic
};

class Derived : public Base {
	//do nothing is not polymorphic
};

int main() {
	Derived MyDerived;
	Derived* pMyDerived = &MyDerived;

	//conversion to base class
	Base* pBaseTest = dynamic_cast<Base *>(pMyDerived);
	cout << "pMyDerived " << (pBaseTest ? " is" : "is not") << " a Base*." << endl;
}