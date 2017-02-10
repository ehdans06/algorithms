#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class _data {
public:
	_data() :length(1) {};
	int key;
	int length;
	int row;
	int col;
	bool operator >(_data& da) {
		return key > da.key;
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	_data** Arr = new _data*[m + 1];
	priority_queue<_data, vector<_data>, greater<_data>> qu;
	for (int i = 0; i <= m; i++) {
		_data* temp = new _data[n + 1];
		Arr[i] = temp;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Arr[i][j].key;
			Arr[i][j].row = i; Arr[i][j].col = j;
			qu.push(Arr[i][j]);
		}
	}
	while (!qu.empty()) {
		_data current = qu.top();
		if (current.row != 1 && current.key > Arr[current.row - 1][current.col].key && current.length < Arr[current.row - 1][current.col].length + 1) {
			Arr[current.row][current.col].length = Arr[current.row - 1][current.col].length + 1;
		}
		if (current.row != m && current.key > Arr[current.row + 1][current.col].key && current.length < Arr[current.row + 1][current.col].length + 1) {
			Arr[current.row][current.col].length = Arr[current.row + 1][current.col].length + 1;
		}
		if (current.col != 1 && current.key > Arr[current.row][current.col - 1].key && current.length < Arr[current.row][current.col - 1].length + 1) {
			Arr[current.row][current.col].length = Arr[current.row][current.col - 1].length + 1;
		}
		if (current.col != n && current.key > Arr[current.row][current.col + 1].key && current.length < Arr[current.row][current.col + 1].length + 1) {
			Arr[current.row][current.col].length = Arr[current.row][current.col + 1].length + 1;
		}
	}
	cout << Arr[1][1].length;
}
