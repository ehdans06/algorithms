
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* Arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> Arr[i];
	}
  // score[x] = 가장 앞에 연결된 포트가 x일 때 그 때의 개수
	int* score = new int[n + 1];
  score[n] = 1;
	int maximum = 0;
	for (int i = n - 1; i > 0; i--) {
		int temp = 0;
		for (int j = i + 1; j <= n; j++) {
			if (Arr[i] < Arr[j]) {
				temp = max(temp, score[j]);
			}
		}
		score[i] = temp + 1;
		maximum = max(maximum, score[i]);
	}
	cout << maximum;
}
