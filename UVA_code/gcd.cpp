#include<bits/stdc++.h>
using namespace std;
int d = -1;
pair<int,int> extendedEuclid(int& a, int& b) {
	if (b == 0) {
		d = a;  return make_pair(1,0);
	}
	int temp = a % b;
	pair<int,int> res = extendedEuclid(b,temp);
	int x1 = res.second;
	int y1 = res.first - (a / b) * res.second;
	return make_pair(x1, y1);
}
int main() {
	int total, c1, c2, n1, n2;
	while (1) {
		scanf("%d",&total);
		if (total == 0) {
			break;
		}
		d = -1;
		scanf("%d %d",&c1,&n1);
		scanf("%d %d",&c2,&n2);
		int x, y;
		pair<int, int> pr = extendedEuclid(n1, n2);
		if (total % d || d == -1) {
			printf("failed\n");
		}
		else {
			x = pr.first;
			y = pr.second;
			int tx = x * total / d;
			int ty = y * total / d;
			//printf("%d %d,%d,",tx,ty,d);
			//printf("%lf", (double(c1) / double(n1)));
			if (c1*n2 > c2*n1) {
			while (tx < 0) {
				tx += (n2 / d);
				ty -= (n1 / d);
			}
			while (ty < 0) {
				tx -= (n2 / d);
				ty += (n1 / d);
			}
			if (tx < 0) {
				printf("failed\n");

			}
			else {
				while (tx - (n2 / d) >= 0) {
					tx -= (n2 / d);
					ty += (n1 / d);
				}
				printf("%d %d\n", tx, ty);
			}

		}
			else {
			//printf("here");
			while (ty < 0) {
				tx -= (n2 / d);
				ty += (n1 / d);
			}
			while (tx < 0) {
				tx += (n2 / d);
				ty -= (n1 / d);
			}
			if (ty < 0) {
				printf("failed\n");
			}
			else {
				while (ty - (n1 / d) >= 0) {
					tx += (n2 / d);
					ty -= (n1 / d);
				}
				printf("%d %d\n", tx, ty);
			}
		}
		}
	}
	return 0;
}