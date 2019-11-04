#include <bits/stdc++.h>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	map<int, int> num_map;
	map<int, int> num_map_f;
	stack<int> print_stack;
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		num_map_f[temp] += 1;
		print_stack.push(temp);
	}
	cout << num_map_f.size() << endl;
	int size = print_stack.size();
	stack<int> real;
	for (int i = 0; i < size; i++) {
		int temp = print_stack.top();
		if (num_map[temp] == 0) {
			num_map[temp] = 1;
			real.push(temp);
		}
		print_stack.pop();
	}
	size = real.size();
	for (int i = 0; i < size; i++) {
		cout << real.top() << " ";
		real.pop();
	}
	return 0;
}
