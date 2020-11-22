#include <limits>
#include <iostream>

using namespace std;

short ErrorCode;

unsigned short Add(unsigned short addend1, unsigned short addend2) {
	unsigned long sum = addend1 + addend2;
	if (sum > USHRT_MAX) {
		ErrorCode = -1;
		return (unsigned short) sum;
	}
	return 0;
}

int main() {
	unsigned short Result = Add(12345, 54321);
	if (ErrorCode == -1)
		cout << "Depasire!\n";
	else
		cout << "Raspunsul este " << Result << endl;
}