//BOJ2011

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> score(n + 1, 0);
	s.insert(0, "0");
	score[0] = 1;
	for (int i = 0; i < n; i++) {
		if (s.at(i + 1) == '0') {
			if (s.at(i) == '1' || s.at(i) == '2') {
				score[i + 1] = score[i - 1];
			}
			else {
				break;
			}
		}
		else {
			if (s.at(i) == '1' || (s.at(i) == '2' && (int)s.at(i + 1) - 48 <= 6)) {
				score[i + 1] = (score[i] + score[i - 1])%1000000;
			}
			else {
				score[i + 1] = score[i];
			}
		}
	}
	cout << score[n];
}
