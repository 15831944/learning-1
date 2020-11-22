#include <limits>
#include <iostream>
#include <eh.h>

using namespace std;
class MyMemoryHogClass {
public:
	~MyMemoryHogClass() {
		cout << "In destructorul MyMemoryHogClass.\n";
	}
};
unsigned short Add(unsigned short addend1, unsigned short addend2) {
	MyMemoryHogClass Hog;
	unsigned long sum = addend1 + addend2;
	if (sum > USHRT_MAX)
		throw 1;
	return (unsigned short)sum;
}

int main() {
	try {
		unsigned short Result = Add(12345, 54321);
		cout << "Rezultatul este " << Result << endl;
	}
	catch (int ErrorCode) {
		cout << "A aparut o depasire ! ErrorCode = " << ErrorCode << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}