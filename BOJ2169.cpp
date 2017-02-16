#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int** Arr = new int*[n + 1];
	int** score = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		Arr[i] = new int[m + 1];
		score[i] = new int[m + 1];
		for (int j = 1; j <= m; j++) {
			cin >> Arr[i][j];
			score[i][j] = (1 << 31);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				int temp = 0;
				for (int k = 1; k <= j; k++) {
					temp += Arr[i][k];
				}
				score[i][j] = temp;
			}
			else {
				//left
				int temp = 0;
				for (int k = j; k > 0; k--) {
					temp += Arr[i][k];
					score[i][j] = max(score[i][j], score[i - 1][k] + temp);
				}
				//right
				int temp1 = 0;
				for (int k = j; k <= m; k++) {
					temp1 += Arr[i][k];
					score[i][j] = max(score[i][j], score[i - 1][k] + temp1);
				}
			}
		}
	}
	cout << score[n][m];
}
