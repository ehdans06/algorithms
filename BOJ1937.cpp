//BOJ1937
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class _data {
public:
	_data() :key(0), length(1) {};
	int key;
	int length;
};

class loc {
public:
	loc(int i, int j, int k) :x(i), y(j), key(k) {};
	int x;
	int y;
	int key;
	bool operator > (const loc& b) const {
		return key > b.key;
	}
};

int main() {
	int n;
	cin >> n;
	_data** forest = new _data*[n + 1];
	priority_queue<loc, vector<loc>, greater<loc>> min_heap;
	for (int i = 1; i <= n; i++) {
		forest[i] = new _data[n + 1];
		for (int j = 1; j <= n; j++) {
			cin >> forest[i][j].key;
			loc temp(i, j, forest[i][j].key);
			min_heap.push(temp);
		}
	}
	int max = 0;
	while (!min_heap.empty()) {
		loc current = min_heap.top();
		min_heap.pop();
		if (current.x > 1 && forest[current.x][current.y].key > forest[current.x - 1][current.y].key && forest[current.x][current.y].length < forest[current.x - 1][current.y].length + 1) {
			forest[current.x][current.y].length = forest[current.x - 1][current.y].length + 1;
		}
		if (current.x < n && forest[current.x][current.y].key > forest[current.x + 1][current.y].key && forest[current.x][current.y].length < forest[current.x + 1][current.y].length + 1) {
			forest[current.x][current.y].length = forest[current.x + 1][current.y].length + 1;
		}
		if (current.y > 1 && forest[current.x][current.y].key > forest[current.x][current.y - 1].key && forest[current.x][current.y].length < forest[current.x][current.y - 1].length + 1) {
			forest[current.x][current.y].length = forest[current.x][current.y - 1].length + 1;
		}
		if (current.y < n && forest[current.x][current.y].key > forest[current.x][current.y + 1].key && forest[current.x][current.y].length < forest[current.x][current.y + 1].length + 1) {
			forest[current.x][current.y].length = forest[current.x][current.y + 1].length + 1;
		}
		if (max < forest[current.x][current.y].length)
			max = forest[current.x][current.y].length;
	}
	cout << max;
}
