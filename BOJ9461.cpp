//BOJ 9461
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int count;
	cin >> count;
	while(count){
		long long before, now, num;
		cin >> num;
		long long Arr[10] = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
		long long temp[5] = { 3, 4, 5, 7, 9 };
		if (num <= 10) {
			cout << Arr[num - 1] << endl;
		}
		else {
			before = 9;
			for (int i = 11; i <= num; i++) {
				int n = (i - 1) % 5;
				now = before + temp[n];
				temp[n] = now;
				before = now;
			}
			cout << now << endl;
		}
		count--;
	}
}
