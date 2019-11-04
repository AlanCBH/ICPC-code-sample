#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	int r = num % 3;
	int t = num / 3;
	if (num == 3) {
		printf("1 1 1\n");
	}
	else {
		if (r == 0) {
			
			int k = t / 3;
			int kr = t % 3;
			int a = k * 3 + 1;
			int b = (k + kr - 1) * 3 + 1;
			printf("%d %d %d\n",a,a,b);
		}
		else if (r == 1) {
			
			int k = t / 3;
			int kr = t % 3;
			int a = k * 3 + 1;
			int b = (k + kr - 1) * 3 + 2;
			printf("%d %d %d\n",a, a, b);
			
		}
		else {
			int k = t / 3;
			int kr = t % 3;
			int a = k * 3 + 2;
			int b = (k + kr - 1) * 3 + 1;
			printf("%d %d %d\n",a, a, b);

			
		}
	}


	return 0;
}
