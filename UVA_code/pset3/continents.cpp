#include <bits/stdc++.h>
using namespace std;


int floodfill(char** arr, bool** visited, int r, int c, char land,int row,int column) {
	if (r < 0 || r >= row) {
		return 0;
	}
	if (c < 0) {
		c = c + column;
	}
	c = c % column;
	if (arr[r][c] != land || visited[r][c]) return 0;
	int ans = 1;
	visited[r][c] = true;
	ans += floodfill(arr, visited, r + 1, c, land, row, column);
	ans += floodfill(arr, visited, r - 1, c, land, row, column);
	ans += floodfill(arr, visited, r, c + 1, land, row, column);
	ans += floodfill(arr, visited, r, c - 1, land, row, column);
	return ans;
}
int main() {
	int row, column;
	while (scanf("%d %d",&row,&column) == 2) {
	//cin >> row >> column;
	char** arr;
	bool** visited;
	arr = new char* [row];
	visited = new bool* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new char[column];
		visited[i] = new bool[column];
	}
	for (int i = 0; i < row; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < column; j++) {
			arr[i][j] = temp[j];
			visited[i][j] = false;
		}
	}
	int cur_r, cur_c;
	cin >> cur_r >> cur_c;
	char land = arr[cur_r][cur_c];
	int check = floodfill(arr, visited, cur_r, cur_c, land, row, column);
	int res = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int temp = floodfill(arr, visited, i, j, land, row, column);
			if (temp > res) {
				res = temp;
			}
		}
	}
	//printf("%d\n", check);
	printf("%d\n", res);
	}
	return 0;
}