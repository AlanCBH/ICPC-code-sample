#include <bits/stdc++.h>
using namespace std;


int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n, m;
		cin >> n >> m;
		map<int, vector<int>> num_node;
		vector<vector<int>> mat;
		for (int k = 0; k < m; k++) {
			vector<int> temp;
			mat.push_back(temp);
		}
		map<int, int> sum;
		bool simple = true;
		bool valid = true;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int temp;
				scanf("%d",&temp);
				if (temp == 1) {
					vector<int>::iterator it = find(mat[k].begin(),mat[k].end(), 1);
					if ( it != mat[k].end() ) {
						int prev = it - mat[k].begin();
						vector<int>::iterator c1 = find(num_node[j].begin(), num_node[j].end(), prev);
						vector<int>::iterator c2 = find(num_node[prev].begin(), num_node[prev].end(), j);
						if (c1 != num_node[j].end() || c2 != num_node[prev].end()) {
							simple = false;
						}
						num_node[prev].push_back(j);
						num_node[j].push_back(prev);
					}
				}
				sum[k] += temp;
				mat[k].push_back(temp);
			}
		}
		for (map<int, int>::iterator it = sum.begin(); it != sum.end(); it++) {
			if (it->second != 2) {
				valid = false;
				break;
			}
		}
		if (simple && valid) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	} 
	return 0;
}