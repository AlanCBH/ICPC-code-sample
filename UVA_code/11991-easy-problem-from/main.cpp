// 11991 - An Easy Problem from Rujia Liu
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main() {
	int length, num;
	while (1) {
		if (scanf("%d %d", &length, &num) == EOF) {
			break;
		}
		map<int, vector<int>> node_map;
		for (int i = 0; i < length; i++) {
			int temp;
			scanf("%d",&temp);
			node_map[temp].push_back(i+1);
		}
		for (int i = 0; i < num; i++) {
			int q1, q2;
			scanf("%d %d", &q1, &q2);
			if (node_map[q2].size() >= q1) {
				int indx = (node_map[q2])[q1 - 1];
				printf("%d\n",indx);
				fflush(stdout);
			} else {
				printf("0\n");
				fflush(stdout);
			}
		}
	}
	return 0;
}
