#include <bits/stdc++.h>
using namespace std;


void f_update(vector<int> &f_tree, int num, int index, int val) {
	//vector<int> f_tree = *f_ptr;
	index++;
	while (index <= num) {
		f_tree[index] += val;
		index += index & (-index);
	}
}
int getSum(vector<int> &f_tree, int index) {
	//vector<int> f_tree = *f_ptr;
	int sum = 0;
	//index = index + 1;
	while (index > 0) {
		sum += f_tree[index];
		index -= index & (-index);
	}
	return sum;
}

int main() {
	int num;
	int c = 1;
	bool first = true;
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		vector<int> all;
		vector<int> f_tree;
		f_tree.push_back(0);
		for (int i = 0; i < num; i++) {
			int temp;
			scanf("%d",&temp);
			all.push_back(temp);
			f_tree.push_back(0);
		}
		for (int i = 0; i < num; i++) {
			f_update(f_tree, num, i, all[i]);
		}
		if (!first) {
			printf("\n");
		}
		first = false;
		printf("Case %d:\n", c);
		char cur;
		while (1) {
			scanf(" %c",&cur);
			if (cur == 'S') {
				int a, b;
				scanf("%d %d",&a,&b);
				int val = b - all[a-1];
				all[a - 1] = b;
				f_update(f_tree, num, a-1, val);
				/*for (int i = 0; i < num + 1; i++) {
					printf("%d ", f_tree[i]);
				}*/
			}
			else if (cur == 'M') {
				int a, b;
				scanf("%d %d", &a, &b);
				int sum = getSum(f_tree,b) - getSum(f_tree,a-1);
				printf("%d\n",sum);
			}
			else {
				string t;
				cin >> t;
				c++;
				break;
			}
		}
	}
	return 0;
}