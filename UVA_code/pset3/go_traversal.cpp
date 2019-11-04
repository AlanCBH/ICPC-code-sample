#include <bits/stdc++.h>
using namespace std;



int floodfill(int (&arr)[9][9], int (&visit)[9][9],int r, int c,int color) {
	if (r < 0 || r >= 9 || c < 0 || c >= 9) { return 0; }
	else {
		if ((arr[r][c] != color && arr[r][c] != 0)) { 
			return -1; 
		}
		if (visit[r][c] != 0 || arr[r][c] == color) { return 0; }
		bool undecide = false;
		int ans = 1;
		visit[r][c] = 1;
		int temp = floodfill(arr, visit, r + 1, c, color);
		if (temp == -1) {
			//visit[r][c] = -1;
			undecide = true;
		}
		else {
			ans += temp;
		}
		temp = floodfill(arr, visit, r, c + 1, color);
		if (temp == -1) {
			//visit[r][c] = -1;
			undecide = true;
		}
		else {
			ans += temp;
		}
		temp = floodfill(arr, visit, r-1, c, color);
		if (temp == -1) {
			//visit[r][c] = -1;
			undecide = true;
		}
		else {
			ans += temp;
		}
		temp = floodfill(arr, visit, r, c-1, color);
		if (temp == -1) {
			//visit[r][c] = -1;
			undecide = true;
		}
		else {
			ans += temp;
		}
		if (undecide) {
			return -1;
		}
		return ans;
	}
}

int main() {
	//int dr[4] = { 1,0,-1, 0 };
	//int dc[4] = { 0,1, 0,-1 };
	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {
		int arr[9][9];
		int visit[9][9];
		int white = 0;
		int	black = 0;
		for (int i = 0; i < 9; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < 9; j++) {
				visit[i][j] = 0;
				if (temp[j] == 'X') {
					arr[i][j] = 1;
					black++;
				}
				else if (temp[j] == '.') {
					arr[i][j] = 0;
				}
				else {
					arr[i][j] = -1;
					white++;
				}
			}
		}
		if (white != 0 || black != 0) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					//printf("%d", arr[i][j]);
					int temp = floodfill(arr, visit, i, j, 1);
					if (temp != -1) {
						black += temp;
					}
				}
				//printf("\n");
			}
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					visit[i][j] = 0;
				}
			}
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					int temp = floodfill(arr, visit, i, j, -1);
					if (temp != -1) {
						white += temp;
					}
				}
			}
		}
		printf("Black %d White %d\n", black, white);
	}
	return 0;
}