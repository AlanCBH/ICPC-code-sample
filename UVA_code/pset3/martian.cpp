#include <bits/stdc++.h>
using namespace std;
//0 explored
//1 visited
//-1 unvisited
vector<int> connection(50000+1);
vector<int> connected(50000+1);
int visited[50000 + 1];
int dfs(int cur, int step, bool& cycle) {//vector<int> connection, int* visited,vector<int> &connected,int step,bool& cycle) {
	if (visited[cur] == 1) {
		return connected[cur];
	}
	else {
		int v = 1;
		visited[cur] = 0;
		int next = connection[cur];
		if (visited[next] == -1) {
			v += dfs(next, step + 1, cycle);// connection, visited, connected,step + 1, cycle);
		}
		else if (visited[next] == 1) {
			v += connected[next];
		}
		else {
			cycle = true;
		}
		if (cycle) {
			connected[cur] = v + step;
		}
		else {
			connected[cur] = v;
		}
		visited[cur] = 1;
		return v;
	}
}

int main() {
	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {
		int population;
		cin >> population;
		//vector<int> connection(population+1);
		//int visited [population + 1];
		//vector<int> connected(population+1);
		int u, v;
		for (int i = 0; i < population; i++) {
			cin >> u >> v;
			visited[u] = -1;
			connection[u] = v;
		}
		int real_max = 0;
		int real_index = 0;
		for (int i = 1; i <= population; i++) {
			bool cycle = false;
			int temp = dfs(i, 0, cycle);// connection, visited, connected, 0, cycle);
			if (temp > real_max) {
				real_max = temp;
				real_index = i;
			}
			//printf("%d\n",connected[i]);
				//memset(visited, 0, (population + 1) * sizeof(bool));
		}
	
		printf("Case %d: %d\n",a+1,real_index);
	}
	return 0;
}