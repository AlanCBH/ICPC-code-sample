#include <bits/stdc++.h>
using namespace std;
int dungenon[30][30][30];
int d_visited[30][30][30];
int sx, sy, sz,L,R,C;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int bfs() {
	queue<tuple<int, int, int>> unvisited;
	unvisited.push(make_tuple(sx,sy,sz));
	d_visited[sx][sy][sz] = 1;
	queue<tuple<int, int, int>> next_to_visit;
	int min = 0;
	bool reach = false;
	while (!unvisited.empty()) {
		auto f = unvisited.front();
		unvisited.pop();
		if (dungenon[get<0>(f)][get<1>(f)][get<2>(f)] == 2) {
			reach = true;
			break;
		}
		else if (dungenon[get<0>(f)][get<1>(f)][get<2>(f)] > 0) {
			for (int i = 0; i < 6; i++) {
				if (get<0>(f) + dx[i] >= L || get<0>(f) + dx[i] < 0 || get<1>(f) + dy[i] >= R ||
					get<1>(f) + dy[i] < 0 || get<2>(f) + dz[i] >= C || get<2>(f) + dz[i] < 0) {
					continue;
				} else if (dungenon[get<0>(f)+dx[i]][get<1>(f)+dy[i]][get<2>(f)+dz[i]] > 0 && 
					d_visited[get<0>(f) + dx[i]][get<1>(f) + dy[i]][get<2>(f) + dz[i]] == 0) {
					next_to_visit.push(make_tuple(get<0>(f) + dx[i], get<1>(f) + dy[i], get<2>(f) + dz[i]));
					d_visited[get<0>(f) + dx[i]][get<1>(f) + dy[i]][get<2>(f) + dz[i]] = 1;
				} 
			}
		}
		if (unvisited.empty()) {
			min++;
			while (!next_to_visit.empty()) {
				unvisited.push(next_to_visit.front());
				next_to_visit.pop();
			}
		}

	}
	if (reach) {
		return min;
	}
	else {
		return -1;
	}
}


int main() {
	//int L, R, C;
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) {
			break;
		}
		//int dungenon[L][R][C];
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string temp;
				cin >> temp;
				for (int k = 0; k < C; k++) {
					d_visited[i][j][k] = 0;
					if (temp[k] == '.') {
						dungenon[i][j][k] = 1;
					}
					else if (temp[k] == '#') {
						dungenon[i][j][k] = 0;
					}
					else if (temp[k] == 'E') {
						dungenon[i][j][k] = 2;
					}
					else {
						dungenon[i][j][k] = 3;
						sx = i;
						sy = j;
						sz = k;
					}
				}
			}
		}
		int min = bfs();
		if (min == -1) {
			printf("Trapped!\n");
		} else {
			printf("Escaped in %d minute(s).\n",min);
		}
	}

	return 0;
}