#include <iostream>

using namespace std;

class Base {
	//do nothing
	virtual void Nothing() {};
};

class Derived : public Base {
	//do nothing
};

int main() {
	Derived MyDerived;
	Derived* pMyDerived = &MyDerived;

	//conversion to base class
	Base* pBaseTest = dynamic_cast<Base *>(pMyDerived);
	cout << "pMyDerived " << (pBaseTest ? " is" : "is not") << " a Base*." << endl;

	//conversion to base class
	if (pBaseTest) {
		Derived* pDerivedTest = dynamic_cast<Derived *>(pBaseTest);
		cout << "pBaseTest " << (pDerivedTest ? " is" : "is not") << " a Derived*." << endl;
	}
}