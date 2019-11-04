#include <bits/stdc++.h>
using namespace std;

int main() {
	int p1, p2;
	int c = 0;
	while (1) {
		c++;
		scanf("%d %d",&p1, &p2);
		if (p1 == 0 && p2 == 0) {
			break;
		}
		vector<pair<int, int>> all_edges;
		int real_max = 0;
		while(1) {
			if (p1 == 0 && p2 == 0) {
				break;
			}
			if (p1 > real_max) {
				real_max = p1;
			}
			if (p2 > real_max) {
				real_max = p2;
			}
			all_edges.push_back(make_pair(p1, p2));
			scanf("%d %d",&p1,&p2);
		}
	
		//printf("%d\n",real_max);
		int arr[real_max][real_max];
		for (int i = 0; i < real_max; i++) {
			for (int j = 0; j < real_max; j++) {
				arr[i][j] = 10000000;
			}
		}
		for (int i = 0; i < all_edges.size(); i++) {
			arr[all_edges[i].first-1][all_edges[i].second-1] = 1;
		}
		for (int i = 0; i < real_max; i++) {
			arr[i][i] = 0;
		}
		for (int k = 0; k < real_max; k++) {
			for (int i = 0; i < real_max; i++) {
				for (int j = 0; j < real_max; j++) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
		double total = 0;
		double total_num = 0;
		for (int i = 0; i < real_max; i++) {
			for (int j = 0; j < real_max; j++) {
				if (i != j && arr[i][j] < 10000000) {
					total += arr[i][j];
					total_num++;
				}
			}
		}
		//printf("%f\n",total_num);
		double aver = total/total_num;
		printf("Case %d: average length between pages = %.3f clicks\n",c,aver);
	}
	return 0;
}