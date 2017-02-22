#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k, Arr[301][301]; // Arr[현재 위치][방문도시수]

int main() {
	cin >> n >> m >> k;
	memset(Arr, 0xEE, sizeof(Arr));
	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		vector<pair<int,int>> temp;
		adj[i] = temp;
	}
	for (int i = 1; i <= k; i++) {
		int u, v, val;
		cin >> u >> v >> val;
		if(u < v)
			adj[u].push_back(pair<int, int>(v, val));
	}
	Arr[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		while (!adj[i].empty()) {
			pair<int, int> edge = adj[i].back();
			for (int j = 1; j < m; j++) {
				Arr[edge.first][j + 1] = max(Arr[edge.first][j + 1], Arr[i][j] + edge.second);
			}
			adj[i].pop_back();
		}		
	}
	int rtn = 0;
	for (int i = 2; i <= m; i++) {
		rtn = max(rtn, Arr[n][i]);
	}
	cout << rtn;
}
