#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main() {
	stack<int> s_arr;
	queue<int> q_arr;
	int num, ablity;
	scanf("%d %d",&num,&ablity);
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d",&temp);
		s_arr.push(temp);
		q_arr.push(temp);
	}
	int res = 0;
	while (1) {
		if (res >= num) {
			break;
		}
		if (q_arr.front() > ablity && s_arr.top() > ablity) {
			break;
		}
		else if (q_arr.front() <= ablity) {
			q_arr.pop();
			res++;
		} else if (s_arr.top() <= ablity) {
			s_arr.pop();
			res++;
		}
	}
	printf("%d\n",res);
	return 0;
}