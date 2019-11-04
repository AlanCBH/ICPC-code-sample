#include <bits/stdc++.h>
using namespace std;

int bfs(int start,int target, map<int, vector<int>> adj_list) {
	queue<int> q;
	queue<int> cur_q;
	map<int, int> visited;
	q.push(start);
	int cur_dist = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i < adj_list[t].size(); i++) {
			int temp = adj_list[t][i];
			if (visited[temp] == 0) {
				cur_q.push(temp);
				visited[temp] = 1;
			}
			if (temp == target) {
				return cur_dist;
			}
		}
		if (q.empty() && !cur_q.empty()) {
			cur_dist++;
			while (!cur_q.empty()) {
				q.push(cur_q.front());
				cur_q.pop();
			}
		}
	}
	return -1;
}

/*void bfs_all(vector<vector<int>> &dist, vector<string> all_words, map<int,vector<int>> adj_list) {
	for (int i = 0; i < all_words.size(); i++) {
		vector<int> temp;
		dist.push_back(temp);
		for (int j = 0; j < all_words.size(); j++) {
			dist[i].push_back(INT_MAX);
		}
	}
	for (int i = 0; i < all_words.size(); i++) {
		bfs(i, adj_list, dist);
	}
}*/

int main() {
	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {
		map<int, vector<int>> adj_list;
		map<string, int> int_map;
		string word;
		cin >> word;
		vector<string> all_words; int index{};
		while (word != "*") {
			int_map[word] = index;
			all_words.push_back(word);
			for (int i = 0; i < index; i++) {
				if (word.length() == all_words[i].length()) {
					int count = 0;
					for (int j = 0; j < word.length(); j++) {
						if (word[j] != all_words[i][j]) {
							count++;
						}
						if (count > 1) {
							break;
						}
					}
					if (count == 1) {
						adj_list[index].push_back(i);
						adj_list[i].push_back(index);
					}
				}
			}
			index++;
			getline(cin,word);
		}
		while (1) {
			string query;
			getline(std::cin, query);
			if (query.length() == 0) {
				break;
			} else {
				size_t pos = query.find(" ");
				string first = query.substr(0, pos);
				string second = query.substr(pos+1);
				int first_index = int_map[first];
				int second_index = int_map[second];
				int dist = 0;
				if (first_index != second_index) {
					dist = bfs(first_index, second_index, adj_list);
				}
				cout << first << " " << second << " " << dist << endl;
			}
		}
		if (a != num-1) {
			printf("\n");
		}
	}
	return 0;
}
