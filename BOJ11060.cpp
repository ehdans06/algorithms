//boj11060
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> Arr(n + 1);
	vector<int> score(n + 1, -1);
	for (int i = 1; i <= n; i++)
		cin >> Arr[i];
	score[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= Arr[i] && (i + j) <= n && score[i] != -1; j++) {
			if (score[i + j] > score[i] + 1 || score[i + j] == -1) {
				score[i + j] = score[i] + 1;
			}
		}
	}
	cout << score[n];
}
