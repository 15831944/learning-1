#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
	//does nothing
	virtual void Nothing() {};
};

class Middle : public Base {
	//does nothing
};

class Derived : public Middle {
	//does nothing
};

//print relation using before()
void ShowBefore(const type_info& info1, const type_info& info2) {
	cout << info1.name();
	cout << (info1.before(info2) ? " is " : " is not ");
	cout << "before the " << info2.name() << endl;
}

int main() {
	ShowBefore(typeid(Base), typeid(Middle));
	ShowBefore(typeid(Base), typeid(Derived));
	ShowBefore(typeid(Middle), typeid(Base));
	ShowBefore(typeid(Middle), typeid(Derived));
	ShowBefore(typeid(Derived), typeid(Base));
	ShowBefore(typeid(Derived), typeid(Middle));
}