#include<bits/stdc++.h>
using namespace std;

bool check_diff(int num,int other_num) {
	if (num >= 100000) {
		return false;
	}
	else {
		vector<int> digits;
		for (int i = 0; i < 5; i++) {
			int d = other_num % 10;
			other_num = other_num / 10;
			if (find(digits.begin(), digits.end(), d) != digits.end()) {
				return false;
			}
			digits.push_back(d);
		}
		for (int i = 0; i < 5; i++) {
			int d = num % 10;
			num = num / 10;
			if (find(digits.begin(), digits.end(),d) != digits.end()) {
				return false;
			}
			digits.push_back(d);
		}
		return true;
	}
}

int main() {
	int num = 0;
	bool first = true;
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		if (first) {
			first = false;
		}
		else {
			printf("\n");
		}
		bool found = false;
		for (int i = 1234; i < 50000; i++) {
			if (check_diff(num * i,i)) {
				found = true;
				printf("%05d / %05d = %d\n",num*i,i,num);
			}
		}
		if (!found) {
			printf("There are no solutions for %d.\n",num);
		}
		
	
	}

	return 0;
}
