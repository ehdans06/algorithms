#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	s1.insert(0, " ");
	s2.insert(0, " ");
	int size1 = s1.size();
	int size2 = s2.size();
	int** score = new int*[size1];
	for (int i = 0; i < size1; i++) {
		score[i] = new int[size2];
		for (int j = 0; j < size2; j++) {
			score[i][j] = -1;
		}
	}
	int maximum = 0;
	for (int i = 0; i <= size1 - 1; i++) {
		for (int j = 0; j <= size2 - 1; j++) {
			if (i == 0 || j == 0) {
				score[i][j] = 0;
			}
			else if (s1.at(i) != s2.at(j)) {
				score[i][j] = 0;
			}
			else {
				score[i][j] = score[i - 1][j - 1] + 1;
				maximum = max(maximum, score[i][j]);
			}	
		}
	}
	cout << maximum;
}
