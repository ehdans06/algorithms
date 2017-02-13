//BOJ10164
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int** Arr = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		Arr[i] = new int[m + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || j == 1) {
				Arr[i][j] = 1;
			}
			else {
				Arr[i][j] = Arr[i - 1][j] + Arr[i][j - 1];
			}
		}
	}
	int loc;
	cin >> loc;
	if (loc == 0) {
		cout << Arr[n][m];
	}
	else {
		int co = (loc - 1) % m + 1;
		int ro = (loc - 1) / m + 1;
		cout << Arr[ro][co] * Arr[n - ro + 1][m - co + 1];
	}
}
