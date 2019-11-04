#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	int num_one = 0;
	int num_two = 0;
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d",&temp);
		if (temp == 1) {
			num_one++;
		}
		else {
			num_two++;
		}
	}
	if (num_one >= 3) {
		printf("1 1 1");
		for (int i = 0; i < num_two; i++) {
			printf(" 2");
		}
		for (int i = 0; i < num_one-3; i++) {
			printf(" 1");
		}
		printf("\n");
	}
	else {
		if (num_one > 0 && num_two > 0) {
			printf("2 1");
			for (int i = 0; i < num_two-1; i++) {
				printf(" 2");
			}
			for (int i = 0; i < num_one-1; i++) {
				printf(" 1");
			}
			printf("\n");
		}
		if (num_one == 0) {
			for (int i = 0; i < num_two-1; i++) {
				printf("2 ");
			}
			printf("2\n");
		}
		if (num_two == 0) {
			for (int i = 0; i < num_one-1; i++) {
				printf("1 ");
			}
			printf("1\n");
		}
	}

	return 0;
}