#include <iostream>
#include <vector>
#include <algorithm>
#define INF (~(1<<31)>>1)
using namespace std;

int main() {
	int n, a, b, count;
	cin >> n;
	vector<vector<int>> before(n + 1);
	vector<vector<int>> current(n + 1);
	vector<vector<int>> relax(n + 1);
	for (int i = 0; i <= n; i++) {
		vector<int> temp1(n + 1, INF);
		vector<int> temp2(n + 1, INF);
		vector<int> temp3(n + 1, INF);
		before[i] = temp1;
		current[i] = temp2;
		relax[i] = temp3;
	}
	cin >> a >> b;
	before[a][b] = 0;
	cin >> count;
	vector<int> Arr(count + 1);
	for (int i = 1; i <= count; i++) {
		cin >> Arr[i];
	}
	int minimum = INF;
	for (int cnt = 1; cnt <= count; cnt++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i == Arr[cnt] || j == Arr[cnt]) {
					for (int k = 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							current[i][j] = min(current[i][j], before[k][l] + abs(i - k) + abs(j - l));
						}
					}
				}
				if (cnt == count)
					minimum = min(minimum, current[i][j]);
			}
		}
		copy(current.begin(), current.end(), before.begin());
		copy(relax.begin(), relax.end(), current.begin());
	}
	cout << minimum;
}
