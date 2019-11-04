#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	int arr[num];
	int max = 0;
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
		if (arr[i] > arr[max]) {
			max = i;
		}
	}	
	int r_max = max + 1;
	int	l_max = max - 1;
	int next;
	int elem = 0;
	if (l_max == -1) {
		next = arr[r_max];
	}
	else if (r_max == num) {
		next = arr[l_max];
	}
	else {
		next = std::max(arr[r_max], arr[l_max]);
	}
	while (arr[max] > next) {
		if (next == arr[r_max]) {
			max = r_max;
			r_max = r_max + 1;
			elem++;
		}
		else if (next == arr[l_max]) {
			max = l_max;
			l_max = l_max - 1;
			elem++;
		}
		if (l_max == -1) {
			next = arr[r_max];
		}
		else if (r_max == num) {
			next = arr[l_max];
		}
		else {
			next = std::max(arr[r_max], arr[l_max]);
		}
	}
	if (elem == num-1) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}