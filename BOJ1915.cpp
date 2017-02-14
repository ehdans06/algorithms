#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char** Arr = new char*[n + 1];
	int** score = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		Arr[i] = new char[m + 1];
		score[i] = new int[m + 1];
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				Arr[i][j] = '0';
			}
			else {
				cin >> Arr[i][j];
			}
		}
	}
	int max = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0 || Arr[i][j] == '0') {
				score[i][j] = 0;
			}
			else {
				int temp = min(score[i - 1][j], score[i][j - 1]);
				temp = min(temp, score[i - 1][j - 1]);
				score[i][j] = temp + 1;
			}
			if (max < score[i][j]) {
				max = score[i][j];
			}
		}
	}
	cout << max*max;
}
