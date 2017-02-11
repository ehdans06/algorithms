//BOJ11057
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> before(10);
	vector<int> current(10, 1);
	int sum = 10;
	for (int i = 2; i <= n; i++) {
		sum = 0;
		int temp = 0;
		copy(current.begin(), current.end(), before.begin());
		for (int j = 9; j >= 0; j--) {
			temp += before[j];
			temp %= 10007;
			current[j] = temp;
			sum += current[j];
			sum %= 10007;
		}
	}
	cout << sum;
}
