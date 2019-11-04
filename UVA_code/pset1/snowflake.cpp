#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	for (int i = 0; i < num; i++) {
		int length;
		scanf("%d",&length);
		queue<int> bag;
		map<int, int> num_to_index;
		int next_remove = 0;
		int max = 0;
		for (int j = 0; j < length; j++) {
			int temp;
			scanf("%d",&temp);
			map<int,int>::iterator it = num_to_index.find(temp);
			if (it == num_to_index.end() || num_to_index[temp] < next_remove) {
				num_to_index[temp] = j;
				bag.push(temp);
			}
			else {
				//printf("%d\n", next_remove);
				max = std::max(max,int(bag.size()));
				int fix = num_to_index[temp];
				for (int a = next_remove; a <= fix; a++) {
					/*if (bag.empty()) {
						break;
					}*/
					bag.pop();
				}
				next_remove = fix +1;
				num_to_index[temp] = j;
				bag.push(temp);
			}
		}
		int res = std::max(max, int(bag.size()));
		printf("%d\n",res);
		fflush(stdout);
	}
	return 0;
}
