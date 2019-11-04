// 00978 - Lemming Battle
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	
		int num;
		scanf("%d", &num);
		int B, SG, SB;
		for (int i = 0; i < num; i++) {
			scanf("%d %d %d", &B, &SG, &SB);
			priority_queue<int> green;
			priority_queue<int> blue;
			for (int j = 0; j < SG; j++) {
				int g_power;
				scanf("%d", &g_power);
				green.push(g_power);
			}
			for (int j = 0; j < SB; j++) {
				int b_power;
				scanf("%d", &b_power);
				blue.push(b_power);
			}
			while (!green.empty() && !blue.empty()) {
				int battle = min( min(int(green.size()),int(blue.size()) ) ,B);
				queue<int> g_queue;
				queue<int> b_queue;
				for (int i = 0; i < battle; i++) {
					int green_p = green.top();
					green.pop();
					int blue_p = blue.top();
					blue.pop();
					if (green_p > blue_p) {
						g_queue.push(green_p - blue_p);
					}
					else if (blue_p > green_p) {
						b_queue.push(blue_p - green_p);
					}
				}
				while (!g_queue.empty()) {
					green.push(g_queue.front());
					g_queue.pop();
				}
				while (!b_queue.empty()) {
					blue.push(b_queue.front());
					b_queue.pop();
				}
			}
			if (green.empty() && blue.empty()) {
				printf("green and blue died\n");
			}
			else if (blue.empty()) {
				printf("green wins\n");
				while (!green.empty()) {
					printf("%d\n", green.top());
					green.pop();
				}
			}
			else {
				printf("blue wins\n");
				while (!blue.empty()) {
					printf("%d\n", blue.top());
					blue.pop();
				}
			}
			if (i != num - 1) {
				printf("\n");
			}
		}
		
	return 0;
}
