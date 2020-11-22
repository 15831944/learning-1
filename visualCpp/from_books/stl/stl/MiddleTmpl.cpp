#include <iostream>

//aceasta este definitia sablonului functiei
template<class Type>
Type Middle(Type a, Type b, Type c) {
	return (a <= b ? (b <= c ? b : Middle(a, c, b)) : Middle(b, a, c));
}

int main() {
	std::cout << "Middle(3,12,5) is " << Middle(3, 12, 5)<<std::endl;
}