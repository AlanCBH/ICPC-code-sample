#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	
	while(1) {
		
		int total, times;
		scanf("%d %d",&total,&times) ;
		if (total == 0 && times == 0) {
			break;
		}
		
		//bool arr[total];
		int right[total];
		int left[total];
		
		for (int i = 0; i < total; i++) {
			//arr[i] = true;
			left[i] = i-1;
			right[i] = i+1;
		}
		for (int i = 0; i < times; i++) {
			int l_dead,r_dead;
			scanf("%d %d",&l_dead,&r_dead);
			//arr[l_dead-1] = false;
			//arr[r_dead-1] = false;
			int left_buddy,right_buddy;
			left_buddy = left[l_dead-1];
			right_buddy = right[r_dead-1];
			if (left_buddy >= 0) {
				right[left_buddy] = right_buddy;
			}
			if (right_buddy < total) {
				left[right_buddy] = left_buddy;
			}
			//check right_b, left_b
			if (left_buddy == -1) {
				printf("* ");
				fflush(stdout);
			} else {
				printf("%d ",left_buddy+1);
				fflush(stdout);
			}
			if (right_buddy == total) {
				printf("*\n");
				fflush(stdout);
			} else {
				printf("%d\n",right_buddy+1);
				fflush(stdout);
			}
		}
		printf("-\n");
	}
	return 0;
}
