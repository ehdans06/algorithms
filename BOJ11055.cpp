//BOJ11055
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, max = 0;
	cin >> n;
	vector<int> Arr(n);
	vector<int> score(n, 0);
	score[n - 1] = Arr[n - 1];
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (i == j && score[i] < Arr[i])
				score[i] = Arr[i];
			else if (Arr[i] < Arr[j] && score[i] < score[j] + Arr[i])
				score[i] = score[j] + Arr[i];
		}
		if (max < score[i])
			max = score[i];
	}
	cout << max;
}
