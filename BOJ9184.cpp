#include <iostream>
#include <cstring>
using namespace std;
int i, j, k, Arr[21][21][21];

int func(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return func(20, 20, 20);
	}
	if (Arr[a][b][c] != 0xEEEEEEEE) {
		return Arr[a][b][c];
	}
	if (a < b && b < c) {
		Arr[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
		return Arr[a][b][c];
	}
	Arr[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
	return Arr[a][b][c];
}

int main() {
	memset(Arr, 0xEE, sizeof(Arr));
	do {
		cin >> i >> j >> k;
		if(i != -1 || j != -1 || k != -1)
			cout << "w(" << i << ", " << j << ", " << k << ") = " << func(i, j, k) << endl;
	} while (i != -1 || j != -1 || k != -1);
}

