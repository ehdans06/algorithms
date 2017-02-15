//BOJ1890
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<long long>> score(n + 1);
	vector<vector<int>> Arr(n + 1);
	for (int i = 1; i <= n; i++) {
		vector<long long> temp(n + 1, 0);
		vector<int> temp1(n + 1);
		score[i] = temp;
		Arr[i] = temp1;
		for (int j = 1; j <= n; j++) {
			cin >> Arr[i][j];
		}
	}
	score[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k = Arr[i][j];
			if (i + k <= n && k != 0)
				score[i + k][j] += score[i][j];
			if (j + k <= n && k != 0)
				score[i][j + k] += score[i][j];
		}
	}
	cout << score[n][n];
}
