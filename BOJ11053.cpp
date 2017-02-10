//BOJ 11053
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int length, max = 0;
	cin >> length;
	vector<int> Arr(length + 1), score(length + 1, 1);
	for (int i = 1; i <= length; i++)
		cin >> Arr[i];
	for (int i = length-1; i > 0; i--) {
		for (int j = i + 1; j <= length; j++) {
			if (Arr[i] < Arr[j] && score[i] < score[j] + 1)
				score[i] = score[j] + 1;
		}
		if (max < score[i])
			max = score[i];
	}
	cout << max;
}
