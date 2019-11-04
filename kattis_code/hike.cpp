#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int n,m;
	cin >> n >> m;
	int arr[n][m];
	for (int i = 0;i < n; i++) {
		for (int j = 0;j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int res[n][m];
	for (int j = m-1; j >= 0; j--) {
		if (j == m-1) {
			for (int i = 0; i < n; i++) {
				res[i][j] = arr[i][j];
			}
		} else {
			//up and right
			for (int i = 0; i < n; i++) {
				if ( i-1 >= 0 ) {
					int temp = min(res[i-1][j],res[i][j+1]);
					res[i][j] = max(arr[i][j],temp);
				} else {
					res[i][j] = max(arr[i][j],res[i][j+1]);
				}
			}
			//down and right
			for (int i = n-1; i >= 0; i--) {
				if ( i+1 == n ) {
					int dr = max(arr[i][j],res[i][j+1]);
					res[i][j] = min(res[i][j],dr);
				} else {
					int temp = min(res[i+1][j],res[i][j+1]);
					int dr = max(arr[i][j],temp);
					res[i][j] = min(res[i][j],dr);
				}
			}
		}
	}
	int result = res[0][0];
	for (int i = 1; i < n; i++) {
		result = min(result,res[i][0]);
	}
	cout << result << endl;

  

  return 0;
}