//BOJ1912
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0; int max = -1001;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		sum += val;
		if (max < sum)
			max = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << max;
}
