#include <iostream>
using namespace std;

// recursive ver.
/*
bool ispell(int a, int b, int* Arr, int** score) {
	if (score[a][b] == 2) {
		if (a == b) {
			score[a][b] = 1;
			return 1;
		}
		if (b == a + 1) {
			if (Arr[a] == Arr[b]) {
				score[a][b] = 1;
				return 1;
			}
			else {
				score[a][b] = 0;
				return 0;
			}
		}
		if (Arr[a] == Arr[b] && ispell(a + 1, b - 1, Arr, score)) {
			score[a][b] = 1;
			return 1;
		}
		else {
			score[a][b] = 0;
			return 0;
		}
	}
	if (score[a][b] == 1)
		return 1;
	return 0;
}*/

int main() {
	int n, count;
	cin >> n;
	int* Arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> Arr[i];
	}
	int** score = new int*[n + 1];
	for (int i = n; i > 0; i--) {
		score[i] = new int[n + 1];
		for (int j = i; j <= n; j++) {
			if (i == j) {
				score[i][j] = 1;
			}
			else if (j == i + 1) {
				if (Arr[i] == Arr[j]) {
					score[i][j] = 1;
				}
				else {
					score[i][j] = 0;
				}
			}
			else {
				if (Arr[i] == Arr[j] && score[i + 1][j - 1] == 1) {
					score[i][j] = 1;
				}
				else {
					score[i][j] = 0;
				}
			}
		}
	}

	cin >> count;
	while (count) {
		int i, j;
		cin >> i >> j;
		cout << score[i][j] << endl;
		count--;
	}
}
