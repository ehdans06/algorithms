//BOJ11054
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* Arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> Arr[i];
	}
	int* LIS = new int[n + 1];
	int* LDS = new int[n + 1];
	for (int i = n; i >= 0; i--) {
		LDS[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (Arr[i] > Arr[j] && LDS[i] < LDS[j] + 1) {
				LDS[i] = LDS[j] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		LIS[i] = 1;
		for (int j = 1; j < i; j++) {
			if (Arr[i] > Arr[j] && LIS[i] < LIS[j] + 1) {
				LIS[i] = LIS[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < LDS[i] + LIS[i] - 1) {
			max = LDS[i] + LIS[i] - 1;
		}
	}
	cout << max;
}
