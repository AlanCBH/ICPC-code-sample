#include <bits/stdc++.h>
using namespace std;
vector<long> stan_win;
int main() {
	long temp = 9;
	bool mt = true;
	while (temp < 4294967295+1) {
		stan_win.push_back(temp);
		if (mt) {
			temp *= 2;
			mt = !mt;
		}
		else {
			temp *= 9;
			mt = !mt;
		}
	}
	long num;
	while (cin >> num) {
		for (int i = 0; i < stan_win.size(); i++) {
			if (stan_win[i] >= num) {
				if (i%2) {
					printf("Ollie wins.\n");
				}
				else {
					printf("Stan wins.\n");
				}
				break;
			}
		}
	}
	return 0;
}