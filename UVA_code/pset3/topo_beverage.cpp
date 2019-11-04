#include <bits/stdc++.h>
using namespace std;
int main() {
	int num;
	int c = 0;
	while (scanf("%d",&num) != EOF) {
		c++;
		map<string, int> int_map;
		map<int, string> string_map;
		map<int, vector<int>> adj_list;
		map<int, bool> visited;
		vector<int> degrees(num);
		vector<int> topo_order;
		for (int i = 0; i < num; i++) {
			string temp;
			cin >> temp;
			int_map[temp] = i;
			string_map[i] = temp;
			degrees[i] = 0;
			visited[i] = false;
		}
		int relate;
		cin >> relate;
		for (int i = 0; i < relate; i++) {
			string weak, strong;
			cin >> weak >> strong;
			adj_list[int_map[weak]].push_back(int_map[strong]);
			degrees[int_map[strong]]++;
		}

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (degrees[j] == 0 && visited[j] == false) {
					topo_order.push_back(j);
					for (int k = 0; k < adj_list[j].size(); k++) {
						degrees[adj_list[j][k]]--;
					}
					visited[j] = true;
					break;
				}
			}
		}

		cout << "Case #" << c << ": Dilbert should drink beverages in this order:";
		for (int i = 0; i < topo_order.size(); i++) {
			cout << " " << string_map[topo_order[i]];
		}
		cout << "." << endl;
		cout << endl;
	}
	return 0;
}