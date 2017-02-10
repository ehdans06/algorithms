//BOJ 2293
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> Arr(n+1), v(k + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> Arr[i];
	for (int i = 0; i <= k / Arr[1]; i++)
		v[i*Arr[1]] = 1;
	for (int i = 2; i <= n; i++) {
		vector<int> temp(k + 1, 0);
		for (int j = 0; j <= k; j++) {
			for (int m = 0; m <= j / Arr[i]; m++) {
				temp[j] += v[j - m*Arr[i]];
			}
		}
		copy(temp.begin(), temp.end(), v.begin());
	}
	cout << v[k];
}
