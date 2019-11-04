#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {
		int node, edge;
		cin >> node >> edge;
		map<int,vector<int>> adj_list;
		for (int b = 0; b < edge; b++) {
			int s, t;
			cin >> s >> t;
			adj_list[s].push_back(t);
			adj_list[t].push_back(s);
		}
	}

	return 0;
}
