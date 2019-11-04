#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	vector<int> levels;
	vector<int> values;
	levels.push_back(0);
	map<int, vector<int>> num_map;
	bool exist = true;
	int max_level = 0;
	for (int i = 0; i < num-1; i++) {
		int temp;
		scanf("%d",&temp);
		levels.push_back(temp);
		if (max_level < temp) {
			max_level = temp;
		}
	}
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		values.push_back(temp);
		if (levels[i]%2 == 1 && temp != -1) {
			exist = false;
			break;
		}
		num_map[levels[i]].push_back(temp);
	}

	int sum = values[0];
	sort(levels.begin(),levels.end());
	for (int i = 2; i < max_level; i = i+2) {
		for (int j = 0; j < levels.size(); j++) {
			if levels[j] == i;
		}
		vector<int> cur = num_map[levels[i]];
		sort(cur.begin(), cur.end());

		vector<int> prev = num_map[levels[i - 2]];
		int pi = prev.size()-1;
		for (int j = cur.size() - 1; j >= 0; j-- ) {
			if (pi == -1) {
				exist = false;
				break;
			}
			if (cur[j] >= prev[pi]) {
				sum += cur[j] - prev[pi];
			}
			else {
				j++;
				pi--;
			}
		}
	}


	if (!exist) {
		printf("-1\n");
	}
	else {
		printf("%d\n", sum);
	}
	return 0;
}