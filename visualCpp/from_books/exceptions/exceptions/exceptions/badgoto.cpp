#include <limits>
#include <iostream>
//bad call does not compile
using namespace std;

unsigned short Add(unsigned short addend1, unsigned short addend2) {
	unsigned long sum = addend1 + addend2;
	if (sum > USHRT_MAX)
		goto OverflowError;
	return (unsigned short)sum;
}
int main() {
	unsigned short Result = Add(12345, 54321);
	cout << "Resultatul este " << Result << endl;
	return EXIT_SUCCESS;
OverflowError:
	cout << "Depasire!";
	return EXIT_FAILURE;
}