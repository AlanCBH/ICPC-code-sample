#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	map<int, int*> money;
	priority_queue <int, vector<int>, greater<int> > arr;
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d",&temp);
		arr.push(temp);
		money[i] = &temp;
	}
	int act;
	scanf("%d",&act);
	for (int i = 0; i < act; i++) {
		int first;
		scanf("%d",&first);
		if (first == 1) {
			int p, m;
			scanf("%d %d",&p,&m);
			*(money[p]) = m;
		}
		else {
			int t;
			scanf("%d",&t);
			while (arr.top() < t) {
				int temp = arr.top();
				arr.pop();
				temp = t;
				arr.push(temp);
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d ",*(money[i]));
	}
	return 0;
}
