//BOJ11048
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int** Arr = new int*[n + 1];
	int** score = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				Arr[i] = new int[m + 1];
				score[i] = new int[m + 1];
			}
			cin >> Arr[i][j];
			score[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				score[i][j] = Arr[i][j];
			}
			else {
				if (j != 1 && score[i][j] < score[i][j - 1] + Arr[i][j]) {
					score[i][j] = score[i][j - 1] + Arr[i][j];
				}
				if (i != 1 && score[i][j] < score[i - 1][j] + Arr[i][j]) {
					score[i][j] = score[i - 1][j] + Arr[i][j];
				}
			}
		}
	}
	cout << score[n][m];
}
