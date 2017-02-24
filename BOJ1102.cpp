#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, p, s, num, rtn, adj[17][17], score[1 << 16];
char ch;

int func(int state, int m) {// state에서 시작해서 p개 이상 켜진 상태까지 가는데 걸리는 cost
	if (score[state] != 0xEEEEEEEE) {
		return score[state];
	}
	if (m >= p) {
		score[state] = 0;
		return score[state];
	}
	score[state] = ~(1 << 31);
	for (int i = 1; i <= n; i++) {
		if ((state | (1<<(i - 1))) == state) {
			for (int j = 1; j <= n; j++) {
				if (((state | (1 << (j - 1))) != state)) {
					int next = state | (1 << (j - 1));
					score[state] = min(score[state], adj[i][j] + func(next, m + 1));
				}
			}
		}
	}
	return score[state];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> adj[i][j];
		}
	}
	s = 0;
	num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		if (ch == 'Y') {
			s += 1 << (i - 1);
			num++;
		}
	}
	cin >> p;
	memset(score, 0xEE, sizeof(score));
	cout << func(s, num);
}
