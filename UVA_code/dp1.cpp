#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int total;
		cin >> total;
		int kind;
		cin >> kind;
		vector<int> all;
		vector<vector< pair<int,int> >> table(kind);
		for (int j = 0; j < kind; j++) {
			int temp;
			cin >> temp;
			all.push_back(temp);
			vector<pair<int,int>> vec_temp;
			table.push_back(vec_temp);
			table[j].push_back(make_pair(1,0));
		}
		sort(all.begin(), all.end());
		reverse(all.begin(), all.end());
		//int t1[kind][total + all[0]+1];
		//int t2[kind][total + all[0]+1];
		//for (int j = 0; j < kind;j++) {
		//	t1[j][0] = 1;
		//	t2[j][0] = 0;
		//}
		for (int j = 1; j <= total+all[0]; j++) {
			//int number = (j) / all[0];
			if (j % all[0] > 0) {
				table[0].push_back(make_pair(0,-1));
				//number++;
			}
			else {
				table[0].push_back(make_pair(1,j/all[0]));
			}
		}
		for (int j = 1; j < kind; j++) {
			for (int k = 1; k <= total+all[0]; k++) {
				int num = k / all[j];
				int min = INT_MAX;
				for (int l = 0; l <= num; l++) {
					if (table[j - 1][k - l * all[j]].first > 0) {
						if (min > table[j - 1][k - l * all[j]].second + l) {
							min = table[j - 1][k - l * all[j]].second + l;
						}
					}
				}
				if (min == INT_MAX) {
					table[j].push_back(make_pair(0, -1));
				}
				else {
					table[j].push_back(make_pair(1, min));
				}
			}
		}
		for (int j = total; j <= total + all[0]; j++) {
			if (table[kind - 1][j].first > 0) {
				cout << j << " " << table[kind - 1][j].second << endl;
				break;
			}
		}
	}

	return 0;
}