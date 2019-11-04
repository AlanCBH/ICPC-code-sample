#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	int x = 0;
	int y = 0;
	while(1) {
		scanf("%d %d",&x,&y);
		if (x == 0 && y == 0) {
			//printf("?\n");
			break;
		} 
		int res;
		if (x >= 3 && y >= 3) {
			res = (x*y+1)/2;
		}
		if (x == 1 || y == 1) {
			res = x*y;
		}
		if (x == 2 && y >= 2) {
			res = (y/4)*4;
			if (y % 4 == 3) {
				res += 4;	
			} else {
				res += (y%4)*2;
			}
		}
		if (y == 2 && x >= 2) {
			res = (x/4)*4;
			if (x % 4 == 3) {
				res += 4;	
			} else {
				res += (x%4)*2;
			}
		}
		printf("%d knights may be placed on a %d row %d column board.\n",res,x,y);
		fflush(stdout);
	}
	return 0;
}
