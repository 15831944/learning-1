//instalarea unei functii terminate()
#include <iostream>
#include <eh.h>
#include <stdlib.h>

using namespace std;

void MyTerminate() {
	cout << "The throwed exception coudl not be distributed.\n";
	cout << "We close the program!\n";
	exit(-1);
}

int main() {
	set_terminate(MyTerminate);
	try {
		throw "Who catch me ??";
	}
	catch (int) {

	}
	catch (char *) { //this do not catch the throwed exception because the exception is const char *

	}
}