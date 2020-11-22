#include <limits>
#include <iostream>
#include <eh.h>

using namespace std;

unsigned short Add(unsigned short addend1, unsigned short addend2) {
	unsigned long sum = addend1 + addend2;
	if (sum > USHRT_MAX)
		throw 1;
	return (unsigned short)sum;
}

unsigned short Divide(unsigned short dividend, unsigned short divisor) {
	if (divisor == 0)
		throw "Impartire la zero";
	return (dividend / divisor);
}

int main() {
	try {
		unsigned short Result = Add(12345, 12345);
		cout << "Primul raspuns este " << Result << endl;
		Result = Divide(55, 0);
		cout << "Al doilea raspuns este " << Result << endl;
	}
	catch (int) {
		cout << "A aparut o alta depasire!\n";
	}
	catch (...) {
		cout << "S-a intimplat altceva.\n";
	}
}