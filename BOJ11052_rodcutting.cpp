//BOJ 11052
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int length;
	cin >> length;
	vector<int> Arr(length + 1);
	for (int i = 1; i <= length; i++) {
		cin >> Arr[i];
	}
	vector<int> score(length + 1, 0);
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= i; j++) {
			if (score[i] < score[i - j] + Arr[j])
				score[i] = score[i - j] + Arr[j];
		}
	}
	cout << score[length];
}
