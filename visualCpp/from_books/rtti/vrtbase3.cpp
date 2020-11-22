#include <iostream>
using namespace std;

class Base {
public:
	//do nothing is not polymorphic
	void BaseFunc() { cout << "In Base.\n"; }
	virtual void Nothing() {}
};

class Middle1 : virtual public Base{
public:
	//do nothing is not polymorphic
	void Middle1Func() { cout << "In Middle1.\n"; }
};

class Middle2 :virtual  public Base {
public:
	//do nothing is not polymorphic
	void Middle2Func() { cout << "In Middle2.\n"; }
};

class Derived : public Middle1, public Middle2 {
public:
	//do nothing is not polymorphic
	void DerivedFunc() { cout << "In Derived.\n"; }
};

int main() {
	Derived MyDerived;
	Base * pBase = dynamic_cast<Base *>(&MyDerived);
	pBase->BaseFunc();
	Derived *pDerived = dynamic_cast<Derived *>(pBase);
	pDerived->DerivedFunc();
}