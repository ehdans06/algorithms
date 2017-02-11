//BOJ1699
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* Arr = new int[n + 1];
	Arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		Arr[i] = n + 1;
		for (int j = 1; j <= sqrt(i); j++) {
			if (Arr[i] > Arr[i - j*j] + 1)
				Arr[i] = Arr[i - j*j] + 1;
		}
	}
	cout << Arr[n];
}
