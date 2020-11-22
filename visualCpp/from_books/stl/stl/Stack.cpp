#include <afx.h>
#include <iostream>
#include "Stack.h"
using namespace std;
int main(int argc, char *argv[]) {
	CStack<int > theStack;
	int i = 0;
	while (i < 5) {
		cout << "Pushing a " << i << endl;
		theStack.Push(i++);
	}
	cout << "All elements inserted" << endl;
	while (theStack.IsEmpty() == FALSE) {
		cout << "Extracting " << theStack.Pop() << endl;
	}
	return 0;
}