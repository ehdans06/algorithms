#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m, rtn, adj[402][402]; // 0 = source, 401 = terminal

int main() {
	cin >> n >> m;
	memset(adj, 0, sizeof(adj));
	for (int i = 1; i <= n; i++) {
		adj[0][i]++;
	}
	for (int i = 1; i <= m; i++) {
		adj[200 + i][401]++;
	}
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		for (int j = 1; j <= temp; j++) {
			int temp2;
			cin >> temp2;
			adj[i][200 + temp2]++;
		}
	}
	rtn = 0;
	while (1) { // terminal에 더이상 도달하지 못할 때 까지 BFS를 실행
		queue<int> q;
		int parent[402];
		memset(parent, -1, sizeof(parent));
		q.push(0);
		while (!q.empty()) { // BFS 실행
			int cur = q.front();
			q.pop();
			if (cur == 401)
				break;
			for (int i = 0; i <= 401; i++) {
				if (adj[cur][i] != 0 && parent[i] == -1) { // edge가 있고 아직 방문하지 않았다면
					parent[i] = cur;
					q.push(i);
				}
			}
		}
		if (parent[401] == -1) { // terminal에 도달하지 못하면 종료
			break;
		}
		int v = 401;
		while (v) { // source까지 이동하며 경로의 flow를 추가함
			int u = parent[v];
			adj[u][v]--;
			adj[v][u]++;
			v = u;
		}
		rtn++;
	}
	cout << rtn;
}
