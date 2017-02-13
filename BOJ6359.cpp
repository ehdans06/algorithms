//BOJ6359
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int count;
	cin >> count;
	while (count) {
		int n;
		cin >> n;
		cout << (int)sqrt(n) << endl;
		count--;
	}
}
