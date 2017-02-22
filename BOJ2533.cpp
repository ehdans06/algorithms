#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, v1, v2;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			q.push(i);
		}
	}
	int sum = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (adj[cur].size() == 1) {
			int nex = adj[cur][0];
			for (int i = 0; i < adj[nex].size(); i++) {
				int target = adj[nex][i];
				adj[target].erase(find(adj[target].begin(), adj[target].end(), nex));
				q.push(target);
			}
			adj[nex].clear();
			sum++;
		}
	}
	cout << sum;
}
