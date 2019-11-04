#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		int n, m;
		if (scanf("%d %d", &n, &m) == EOF) {
			break;
		}
		vector<queue<int>> values(m);
		vector<queue<int>> positions(m);
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			queue<int> temp_q;
			for (int j = 0; j < num; j++) {
				int col;
				scanf("%d", &col);
				temp_q.push(col);
			}
			for (int j = 0; j < num; j++) {
				int value;
				scanf("%d", &value);
				int col = temp_q.front();
				temp_q.pop();
				values[col - 1].push(value);
				positions[col - 1].push(i);
			}
		}
		printf("%d %d\n", m, n);
		for (int i = 0; i < m; i++) {
			int size = int(values[i].size());

			if (size == 0) {
				printf("0\n");
			}
			else {
				printf("%d ", size);
			}
			for (int j = 0; j < size; j++) {
				if (j == size - 1) {
					printf("%d\n", positions[i].front() + 1);
					positions[i].pop();
				}
				else {
					printf("%d ", positions[i].front() + 1);
					positions[i].pop();
				}
			}
			if (size == 0) {
				printf("\n");
			}
			for (int j = 0; j < size; j++) {
				if (j == size - 1) {
					printf("%d\n", values[i].front());
					values[i].pop();
				}
				else {
					printf("%d ", values[i].front());
					values[i].pop();
				}
			}

		}
	}
	return 0;
}