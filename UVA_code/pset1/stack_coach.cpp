#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
	int num;
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		while (1) {
			bool end = false;
			stack<int> station;
			int next_arrived = 1;
			bool yes = true;
			for (int i = 0; i < num; i++) {
				int next;
				scanf("%d",&next);
				if (next == 0) {
					end = true;
					break;
				}
				if (next >= next_arrived) {
					for (int i = next_arrived; i <= next; i++) {
						station.push(i);
					}
					next_arrived = next+1;
					station.pop();
				} else if (!station.empty() && next == station.top() ) {
					station.pop();
				} else {
					yes = false;
				}


			}
			if (end) {
				printf("\n");
				break;
			}
			if (yes) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}

	}
	return 0;
}