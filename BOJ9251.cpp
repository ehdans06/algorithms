//BOJ9251
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int** Arr = new int*[a.length() + 1];
	for (int i = 0; i <= a.length(); i++) {
		Arr[i] = new int[b.length() + 1];
	}
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			if (i == 0 || j == 0) {
				Arr[i][j] = 0;
			}
			else {
				if (a.at(i - 1) == b.at(j - 1)) {
					Arr[i][j] = Arr[i - 1][j - 1] + 1;
				}
				else {
					Arr[i][j] = max(Arr[i - 1][j], Arr[i][j - 1]);
				}
			}
		}
	}
	cout << Arr[a.length()][b.length()];
}
