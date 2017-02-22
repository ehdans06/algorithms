#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, s[5001], Arr[5001][5001];

int func(int i, int j) {
	if (Arr[i][j] != 0xEEEEEEEE) {
		return Arr[i][j];
	}
	if (i == j) {
		Arr[i][j] = 0;
		return Arr[i][j];
	}
	if (i + 1 == j && s[i] == s[j]) {
		Arr[i][j] = 0;
		return Arr[i][j];
	}
	if (s[i] == s[j]) {
		Arr[i][j] = func( i + 1, j - 1);
		return Arr[i][j];
	}
	else {
		Arr[i][j] = min(func( i, j - 1), func( i + 1, j)) + 1;
		return Arr[i][j];
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	memset(Arr, 0xEE, sizeof(Arr));
	cout << func(1, n);
}
