//BOJ1309
#include <iostream>
using namespace std;

int main() {
	int n, sum = 3;
	cin >> n;
	//0 = n번째 행에 사자가 없다
	//1 = (n,1)에 사자가 있다
	//2 = (n,2)에 사자가 있다
	int* Arr0 = new int[n + 1];
	int* Arr1 = new int[n + 1];
	int* Arr2 = new int[n + 1];
	Arr0[1] = 1; Arr1[1] = 1; Arr2[1] = 1;
	for (int i = 2; i <= n; i++) {
		Arr0[i] = (Arr0[i - 1] + Arr1[i - 1] + Arr2[i - 1])%9901;
		Arr1[i] = (Arr0[i - 1] + Arr2[i - 1])%9901;
		Arr2[i] = (Arr0[i - 1] + Arr1[i - 1])%9901;
		sum = (Arr0[i] + Arr1[i] + Arr2[i])%9901;
	}
	cout << sum;
}
