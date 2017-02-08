//baekjoon 1010
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int trials;
	cin >> trials;
	while (trials) {
		int N, M;
		cin >> N >> M;
		int** Arr = new int*[N + 1];
		for (int i = 0; i <= N; i++) {
			Arr[i] = new int[M + 1];
			for (int j = 0; j <= M; j++) {
				Arr[i][j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = i; j <= M; j++) {
				sum += Arr[i - 1][j - 1];
				if (i == 1 || i == j) {
					Arr[i][j] = 1;
				} else {
					Arr[i][j] = sum;
				}
			}
		}
		int rtn = 0;
		for (int j = N; j <= M; j++)
			rtn += Arr[N][j];
		cout << rtn << endl;
		trials--;
	}
}
