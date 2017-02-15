#include <iostream>
#include <vector>
using namespace std;

int function(int current, int visited, int** Arr, int** score, int num) {
	if (score[current][visited] != ~(1 << 31)) {
		return score[current][visited];
	}
	if (visited == 0) {
		score[current][visited] = 0;
		return 0;
	}
	int min = ~(1 << 31);
	for (int i = 1; i <= num; i++) {
		if ((visited & (1 << (i - 1))) && Arr[i][current]) {
			int temp = visited ^ (1 << (i - 1));
			if (min > function(i, temp, Arr, score, num) + Arr[i][current]) {
				min = function(i, temp, Arr, score, num) + Arr[i][current];
			}
		}
	}
	score[current][visited] = min;
	return min;
}

int main() {
	int n;
	cin >> n;
	int ** Arr = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		Arr[i] = new int[n + 1];
		for (int j = 1; j <= n; j++) {
			cin >> Arr[i][j];
		}
	}
	int ** score = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		score[i] = new int[1 << n];
		for (int j = 0; j <= (1 << n) - 1; j++) {
			score[i][j] = ~(1 << 31);
		}
	}
	cout << function(1,(1 << n) - 1, Arr, score, n);
}
