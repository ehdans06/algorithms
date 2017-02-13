//BOJ9507
#include <iostream>
using namespace std;

int main() {
	int count;
	cin >> count;
	long long* Arr = new long long[68];
	Arr[0] = 1, Arr[1] = 1, Arr[2] = 2, Arr[3] = 4;
	while (count) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			Arr[i] = Arr[i - 1] + Arr[i - 2] + Arr[i - 3] + Arr[i - 4];
		}
		cout << Arr[n] << endl;
		count--;
	}
}
