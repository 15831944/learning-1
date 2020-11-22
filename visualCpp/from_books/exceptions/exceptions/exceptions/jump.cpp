#include <limits>
#include <iostream>
#include <setjmp.h>

using namespace std;

jmp_buf jmp_info;
unsigned short Add(unsigned short addend1, unsigned short addend2) {
	unsigned long sum = addend1 + addend2;
	if (sum > USHRT_MAX)
		longjmp(jmp_info, -1);
	return (unsigned short)sum;
}

int main() {
	int ErrorCode = setjmp(jmp_info);
	if (ErrorCode == 0) {
		unsigned short Result = Add(12345, 54321);
		cout << "Resultatul este " << Result << endl;
		return EXIT_SUCCESS;
	}
	else {
		cout << "Depasire!" << endl;
		return EXIT_FAILURE;
	}
}