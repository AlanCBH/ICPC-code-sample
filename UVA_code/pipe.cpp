#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {
		int n;
		cin >> n;
		int arr[2][n];
		bool b_arr[2][n + 1];
		for (int i = 0; i < 2; i++) {
			string s_temp;
			cin >> s_temp;
			for (int b = 0; b < n; b++) {
				arr[i][b] = s_temp[b]-'0';
				//printf("%d",arr[i][b]);
				b_arr[i][b] = false;
			}
		}

		
		bool top = true;
		bool bottom = false;
		bool fail = false;
		for (int j = 0; j < n; j++) {
			if ((top && arr[0][j] <= 2) || (bottom  && arr[1][j] <=2) ) {
				continue;
			}
			else if (arr[0][j] > 2 && arr[1][j] > 2) {
				top = bottom;
				bottom = !bottom;
			}
			else {
				top = false;
				bottom = false;
				break;
			}
		}
			
		if (!bottom) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}