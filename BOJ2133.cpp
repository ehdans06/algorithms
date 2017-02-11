//BOJ2133
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> Arr(n + 1, 0);
	Arr[0] = 1;
	Arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i - 2*j >= 0; j++) {
			if (j == 1) {
				Arr[i] += 3 * Arr[i - 2*j];
			}
			else {
				Arr[i] += 2 * Arr[i - 2 * j];
			}
		}
	}
	cout << Arr[n];
}
