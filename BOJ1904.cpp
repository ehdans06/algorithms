//BOJ1904
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* Arr0 = new int[n + 1];
	int* Arr1 = new int[n + 1];
	Arr0[1] = 0; Arr0[2] = 1;
	Arr1[1] = 1; Arr1[2] = 1;
	for (int i = 3; i <= n; i++) {
		Arr0[i] = (Arr0[i - 2] + Arr1[i - 2])%15746;
		Arr1[i] = (Arr0[i - 1] + Arr1[i - 1])%15746;
	}
	cout << (Arr0[n] + Arr1[n]) % 15746;
}
