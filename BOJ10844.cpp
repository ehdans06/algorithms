//BOJ 10844
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int length, rtn = 9;
	cin >> length;
	vector<int> current(10, 1), before(10);
	for (int i = 2; i <= length; i++) {
		copy(current.begin(), current.end(), before.begin());
		rtn = 0;
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				current[j] = before[j + 1];
			}
			else if (j == 9) {
				current[j] = before[j - 1] % 1000000000;
				rtn = (rtn + current[j]) % 1000000000;
			}
			else {
				current[j] = (before[j - 1] + before[j + 1]) % 1000000000;
				rtn = (rtn + current[j]) % 1000000000;
			}
		}
	}
	cout << rtn;
}
