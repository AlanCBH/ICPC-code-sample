#include <bits/stdc++.h>
using namespace std;

int main() {
	string c1,c2;
	int dist{};
	int cur_dist{};
	double oil{};
	int leak{};
	double max_size{};
	double size = 0;
	while(cin >> cur_dist >> c1 >> c2 >> oil) {
		if (cur_dist == 0 && oil == 0) {
			break;
		}
		size += (cur_dist - dist) * oil / 100 + leak * (cur_dist - dist);
		dist = cur_dist;
		while (cin >> cur_dist >> c1) {
			if (c1 == "Goal") {
				size += (cur_dist - dist) * oil / 100 + leak * (cur_dist - dist);
				max_size = max(max_size, size);
				printf("%.3lf\n",max_size);
				size = 0;
				max_size = 0;
				leak = 0;
				dist = 0;
				cur_dist = 0;
				oil = 0;
				break;
			}
			if (c1 == "Gas") {
				cin >> c2;
				size += (cur_dist - dist) * oil / 100 + leak * (cur_dist - dist);
				max_size = max(size, max_size);
				size = 0;
				dist = cur_dist;
			}
			if (c1 == "Mechanic") {
				size += (cur_dist - dist) * oil / 100 + leak * (cur_dist - dist);
				dist = cur_dist;
				leak = 0;
			}
			if (c1 == "Leak") {
				size += (cur_dist - dist) * oil / 100 + leak * (cur_dist - dist);
				dist = cur_dist;
				leak++;
			}
			if (c1 == "Fuel") {
				size += (cur_dist - dist) * oil / 100 + leak * (cur_dist - dist);
				dist = cur_dist;
				cin >> c2 >> oil;
			}
		}
	}
	return 0;
}