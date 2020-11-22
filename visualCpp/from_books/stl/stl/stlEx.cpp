#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arAni[] = { 105,27,89,45 };
int main() {
	vector<int> v;
	v.push_back(434);
	v.push_back(356);
	v.push_back(267);
	v.push_back(987);
	sort(v.begin(), v.end(), greater<int>());
	vector<int>::iterator nrmIter = v.begin();
	vector<int>::reverse_iterator invIter = v.rbegin();
	while (nrmIter != v.end()) {
		cout << *nrmIter << endl;
		++nrmIter;
	}
	while (invIter != v.rend()) {
		cout << *invIter << endl;
		++invIter;
	}

	sort(arAni, arAni + 4, less<int>());
	for (int i = 0; i < 4; i++) {
		cout << arAni[i] << endl;
	}
/* arAni is not a container so ... 
	nrmIter = arAni;
	while (nrmIter != arAni + 4) {
		cout << *nrmIter << endl;
		++nrmIter;
	} */
	return 0;
}