#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
int res[100][100];
int n, m,s,t,f;
vector<int> p;
void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int maxflow() {
	int mf = 0;
	while (1) {
		f = 0;
		vector<int> dist(2 * n, INF);
		dist[s] = 0; queue<int> q; q.push(s);
		p.assign(2 * n, -1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u==t) break;
			for (int v = 0; v < 2 * n;v++) {
				if (res[u][v] > 0 && dist[v] == INF) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0) { break; }
		mf += f;
	}
	return mf;
}

int main() {
	while(1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n;j++) {
				res[i][j] = 0;
			}
		}
		res[0][n] = INF;
		res[n - 1][2*n - 1] = INF;
		s = 0;
		t = 2*n - 1;
		int u, v, c;
		for (int i = 0; i < n - 2; i++) {
			cin >> u >> c;
			res[u-1][u-1 + n] = c;
		}
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> c;
			res[u-1+n][v-1] = c;
			res[v-1 + n][u-1] = c;
		}
		int mf = maxflow();
		printf("%d\n",mf);
	}
	return 0;
}