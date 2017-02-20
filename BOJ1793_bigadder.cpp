#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int a;
string Arr1[251], Arr2[251], Arr3[251];

string reverse(string s1) {
	string rtn;
	int ptr = s1.size();
	for (int i = s1.size() - 1; i >= 0; i--) {
		rtn += s1.at(i);
	}
	return rtn;
}

string add(string s1, string s2) {
	string rtn;
	s1 = reverse(s1), s2 = reverse(s2);
	int up = 0;
	int count = 0;
	while (count <= max(s1.size() - 1, s2.size() - 1) || up != 0) {
		int a1 = 0, a2 = 0;
		if (count <= s1.size() - 1) {
			a1 = (int)(s1.at(count) - '0');
		}
		if (count <= s2.size() - 1) {
			a2 = (int)(s2.at(count) - '0');
		}
		rtn += (char)((a1 + a2 + up) % 10 + '0');
		up = (a1 + a2 + up) / 10;
		count++;
	}
	return reverse(rtn);
}

int main() {
	Arr1[0] = "1", Arr1[1] = "1", Arr2[0] = "0", Arr2[1] = "0", Arr3[0] = "0", Arr3[1] = "0";
	for (int i = 2; i <= 250; i++) {
		Arr1[i] = add(add(Arr1[i - 1], Arr2[i - 1]), Arr3[i - 1]);
		Arr2[i] = add(add(Arr1[i - 2], Arr2[i - 2]), Arr3[i - 2]);
		Arr3[i] = add(add(Arr1[i - 2], Arr2[i - 2]), Arr3[i - 2]);
	}
	while (scanf("%d", &a) != -1) {
		cout << add(add(Arr1[a], Arr2[a]), Arr3[a]) << endl;
	}
}
