#include <bits/stdc++.h>
using namespace std;

int ff();


int main() {
	int num;
	cin >> num;
	int dr[] = {1,0,-1,0};
	int dc[] = {0,1,0,-1};
	for (int a = 0; a < num; a++) {
		int size;
		cin >> size;
		vector<vector<int>> arr(size);
		for (int i = 0; i < size; i++) {

		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size+1; j++) {
				char cur;
				scanf("%c",&cur);
				if (cur == 'x') {
					arr[i][j] = 1;
				}
				else if (cur == '.') {
					arr[i][j] = 0;
				}
				else if (cur == '@') {
					arr[i][j] = -1;
				}
				else {
					continue;
				}
			}
		}
		
	}

	return 0;
}