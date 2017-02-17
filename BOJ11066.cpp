#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#define INF ~(1<<31)
using namespace std;

int func(int a, int b, int* Arr, int** score) {
	if (score[a][b] != -1)
		return score[a][b];
	if (a == b) {
		score[a][b] = 0;
		return 0;
	}
	int minimum = INF;
	for (int i = a; i < b; i++) {
		minimum = min(minimum, Arr[b] - Arr[a - 1] + func(a, i, Arr, score) + func(i + 1, b, Arr, score));
	}
	score[a][b] = minimum;
	return minimum;
}

int main() {
	int count;
	cin >> count;
	while (count) {
		int n;
		cin >> n;
		int* Arr = new int[n + 1];
		int** score = new int*[n + 1];
		Arr[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> Arr[i];
			Arr[i] = Arr[i] + Arr[i - 1];
			score[i] = new int[n + 1];
			for (int j = 1; j <= n; j++) {
				score[i][j] = -1;
			}
		}
		cout << func(1, n, Arr, score) << endl;
		count--;
	}
}
