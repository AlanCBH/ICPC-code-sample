#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	while (1) {
		scanf("%d",&num);
		if (num == 0) {
			break;
		}
		long long total = 0;
		multiset<int> all;
		for (int i = 0; i < num; i++) {
			int bills;
			scanf("%d",&bills);
			for (int j = 0; j < bills; j++) {
				int fig;
				scanf("%d",&fig);
				all.insert(fig);
			}
			
			//multiset<int,greater<int>>::iterator tiny;
			multiset<int>::iterator huge;
			multiset<int>::iterator tiny;
			huge =  all.begin();
			int small = *huge;
			tiny = --all.end();
			int big = *tiny;
			total += big - small;
			all.erase(huge);
			all.erase(tiny);
		}
		printf("%llu\n",total);
		fflush(stdout);
	}
	return 0;
}