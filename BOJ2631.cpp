//BOJ2631
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* Arr = new int[n + 1];
	int* score = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> Arr[i];
	int max = 0;
	for (int i = n; i > 0; i--) {
		score[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (Arr[i] < Arr[j] && score[i] < score[j] + 1) {
				score[i] = score[j] + 1;
			}
		}
		if (max < score[i])
			max = score[i];
	}
	cout << n - max;
}
