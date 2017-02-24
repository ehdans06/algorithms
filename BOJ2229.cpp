#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, Arr[1001], score[1001];

int func(int m) {
	if (m > n) {
		return 0;
	}
	else if (score[m] != -1) {
	}
	else if (m == n) {
		score[m] = 0;
	}
	else {
		int mini = ~(1 << 31), maxi = 0;
		for (int i = m; i <= n; i++) {
			mini = min(mini, Arr[i]);
			maxi = max(maxi, Arr[i]);
			score[m] = max(score[m], maxi - mini + func(i + 1));
		}
	}
	return score[m];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> Arr[i];
	}
	memset(score, -1, sizeof(score));
	cout << func(1);
}
