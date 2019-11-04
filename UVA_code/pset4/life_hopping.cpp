#include <bits/stdc++.h>
using namespace std;
vector<int> time_cost;
vector<int> dist(500);
vector<int> sources;
int k;
map<int, vector<pair<int, int>>> adj_list;
//from GFG
int dijkstra() {
	priority_queue< pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > pq;
	
	for (int i = 0; i < sources.size(); i++) {
		pq.push(make_pair(0, sources[i]));
		dist[sources[i]] = 0;
	}
	
	while (!pq.empty()) {
		
		int u = pq.top().second;
		pq.pop();
		vector<pair<int, int>>::iterator it;
		for (it = adj_list[u].begin(); it != adj_list[u].end(); ++it) {
			int v = (*it).first;
			int weight = (*it).second; 
			if (dist[v] > dist[u] + weight)
			{ 
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	int min_dist = 1000000;
	for (int i = k; i < 500; i += 100) {
		min_dist = min(min_dist, dist[i]);
	}
	return min_dist;
}


int main() {
	int n,temp;
	while (cin >> n >> k) {
		sources.clear();
		adj_list.clear();
		time_cost.clear();
		for (int i = 0; i < n; i++) {
			cin >> temp;
			time_cost.push_back(temp);
		}
		set<int> all_floor;
		dist.assign(500,1000000);
		cin.ignore();
		for (int ii = 0; ii < n; ii++) {
			string s;
			getline(cin, s);
			//cout << s;
			stringstream ss(s);
			vector<int> floors;
			int floor;
			while (ss >> floor) {
				//printf("%d ",floor);
				floors.push_back(ii * 100 +floor);
				all_floor.insert(floor);
				all_floor.insert(ii * 100 + floor);
				if (floor == 0) {
					sources.push_back(ii * 100 + floor);
				}
			}
			/*for (int b = 0; b < floors.size(); b++) {
				printf("%d ",floors[b]);
			}*/
			for (int j = 0; j < floors.size(); j++) {
				if (j+1 < floors.size()) {
					int weight = (floors[j + 1] - floors[j]) * time_cost[ii];
					adj_list[floors[j]].push_back(make_pair(floors[j + 1], weight));
					adj_list[floors[j + 1]].push_back(make_pair(floors[j], weight));
				}
				for (int kk = 1; kk <= ii; kk++) {
					if (all_floor.find(floors[j] - kk*100) != all_floor.end()) {
						adj_list[floors[j]].push_back(make_pair(floors[j]-kk*100, 60));
						adj_list[floors[j]-kk*100].push_back(make_pair(floors[j], 60));
					}
				}
			}
			
		}
		int min_dist = dijkstra();
		if (min_dist == 1000000) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", min_dist);
		}
	}

	return 0;
}