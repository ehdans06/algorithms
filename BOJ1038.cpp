#include <iostream>
#include <algorithm>
using namespace std;

int func1(int a, int b) {
	if (a < b)
		return 0;
	if (a == 0)
		return 1;
	int rtn = 1;
	for (int i = 1; i <= b; i++) {
		rtn = rtn * (a - i + 1) / i;
	}
	return rtn;
}

void func2(int a, int b, int c) {
	if (b > 10) {
		cout << -1 << endl;
		return;
	}
	if (b == 0) {
		cout << endl;
		return;
	}
	if (a >= func1(10, b)) {
		func2(a - func1(10, b), b + 1, 1);
		return;
	}
	if (a >= func1(c, b - 1)) {
		func2(a - func1(c, b - 1), b, c + 1);
		return;
	}
	if (a < func1(c, b - 1)) {
		cout << c;
		func2(a, b - 1, 0);
		return;
	}
}

int main() {
	int a;
	cin >> a;
	func2(a, 1, 0);
}
