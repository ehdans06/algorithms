//BOJ2096
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class _data {
public:
	_data() :key(0),max(0), min(0) {};
	int key;
	int max;
	int min;
};

int main() {
	int n;
	cin >> n;
	vector<_data> before(3);
	vector<_data> current(3);
	for (int i = 1; i <= n; i++) {
		cin >> current[0].key >> current[1].key >> current[2].key;
		_data left;
		left.max = max(before[0].max, before[1].max);
		left.min = min(before[0].min, before[1].min);
		_data right;
		right.max = max(before[1].max, before[2].max);
		right.min = min(before[1].min, before[2].min);
		
		current[0].max = current[0].key + left.max;
		current[0].min = current[0].key + left.min;
		current[1].max = current[1].key + max(left.max, right.max);
		current[1].min = current[1].key + min(left.min, right.min);
		current[2].max = current[2].key + right.max;
		current[2].min = current[2].key + right.min;

		copy(current.begin(), current.end(), before.begin());
	}
	int maximum = max(current[0].max, current[1].max);
	maximum = max(maximum, current[2].max);
	int minimum = min(current[0].min, current[1].min);
	minimum = min(minimum, current[2].min);
	cout << maximum << " " << minimum;
}
