#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int C, S, Q;
void all_pair_dist() {
	for (int k = 0; k < C; k++) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
			}
		}
	}
}
int main() {
	int num = 0;
	bool first = true;
	while (1) {
		cin >> C >> S >> Q;
		if (C == 0 && S == 0 && Q == 0) {
			break;
		}
		if (!first) {
			printf("\n");
		}
		first = false;
		num++;
		map<int, vector<int>> adj_list;
		int s, t, length;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] = 100000;
			}
		}
		for (int i = 0; i < S; i++) {
			cin >> s >> t >> length;
			adj_list[s].push_back(t); adj_list[t].push_back(s);
			arr[s-1][t-1] = length; arr[t-1][s-1] = length;
		}
		all_pair_dist();
		printf("Case #%d\n",num);
		for (int i = 0; i < Q; i++) {
			cin >> s >> t;
			if (arr[s - 1][t - 1] < 100000) {
				printf("%d\n", arr[s - 1][t - 1]);
			}
			else {
				printf("no path\n");
			}
		}
	}
	return 0;
}