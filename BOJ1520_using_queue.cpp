//BOJ 1520
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class loc {
public:
	loc(int i, int j) :ro(i), co(j) {};
	int ro;
	int co;
};

int main() {
	int m, n;
	cin >> m >> n;
	int** Arr = new int*[m + 1];
	for (int i = 1; i <= m; i++)
		Arr[i] = new int[n + 1];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> Arr[i][j];
	
	queue<loc> que;
	int score = 0;
	que.push(loc(1, 1));
	while (!que.empty()) {
		loc current = que.front();
		if (current.ro == m && current.co == n) {
			score++;
		}
		else {
			if (current.ro != 1 && Arr[current.ro][current.co] > Arr[current.ro - 1][current.co]) {
				que.push(loc(current.ro - 1, current.co));
			}
			if (current.ro != m && Arr[current.ro][current.co] > Arr[current.ro + 1][current.co]) {
				que.push(loc(current.ro + 1, current.co));
			}
			if (current.co != 1 && Arr[current.ro][current.co] > Arr[current.ro][current.co - 1]) {
				que.push(loc(current.ro, current.co - 1));
			}
			if (current.co != n && Arr[current.ro][current.co] > Arr[current.ro][current.co + 1]) {
				que.push(loc(current.ro, current.co + 1));
			}
		}
		que.pop();
	}
	cout << score;
}
