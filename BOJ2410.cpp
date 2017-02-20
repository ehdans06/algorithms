#include <iostream>
int n, a[1000001];
int main() {
	std::cin >> n; 
	a[1] = 1; 
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1];
		if (!(i % 2))
			a[i] += a[i / 2];
		a[i] %= 1000000000;
	}std::cout << a[n];
}
