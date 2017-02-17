#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void tracing(int i, int j, string s1, int** trace) {
	if (trace[i][j] == 0) {
		return;
	}
	if (trace[i][j] == 1) {
		tracing(i - 1, j - 1, s1, trace);
		cout << s1.at(i);
		return;
	}
	if (trace[i][j] == 2) {
		tracing(i - 1, j, s1, trace);
		return;
	}
	if (trace[i][j] == 3) {
		tracing(i, j - 1, s1, trace);
		return;
	}
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	s1.insert(0, " ");
	s2.insert(0, " ");
	int size1 = s1.size();
	int size2 = s2.size();
	int** trace = new int*[size1];
	int** score = new int*[size1];
	for (int i = 0; i < size1; i++) {
		trace[i] = new int[size2];
		score[i] = new int[size2];
		for (int j = 0; j < size2; j++) {
			score[i][j] = -1;
		}
	}
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (i == 0 || j == 0) {
				score[i][j] = 0;
				trace[i][j] = 0;
			}
			else if (s1.at(i) != s2.at(j)) {
				score[i][j] = score[i][j - 1];
				trace[i][j] = 3;
				if (score[i][j] < score[i - 1][j]) {
					score[i][j] = score[i - 1][j];
					trace[i][j] = 2;
				}
			}
			else {
				score[i][j] = 1 + score[i - 1][j - 1];
				trace[i][j] = 1;
			}
		}
	}
	cout << score[size1 - 1][size2 - 1] << endl;
	tracing(size1 - 1, size2 - 1, s1, trace);
}
