#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = a; i < b; i++)

using namespace std;


struct s_struct {
	pair<int, int> left;
	pair<int, int> max;
	pair<int, int> right;
	int valid = 1;
	s_struct invalid() {
		s_struct temp;
		temp.valid = 0;
		return temp;
	}
};



s_struct merge(s_struct left_s1, s_struct right_s2) {
	s_struct result;
	result.left = left_s1.left;
	result.right = right_s2.right;
	if (left_s1.max.first == right_s2.max.first) {
		int temp = left_s1.max.second + right_s2.max.second;
		result.max = make_pair(left_s1.max.first, temp);
		if (left_s1.max.first == result.right.first) {
			result.right.second = temp;
		}
		if (left_s1.max.first == result.left.first) {
			result.left.second = temp;
		}
	} 
	else if (left_s1.right.first == right_s2.left.first) {
		int temp = left_s1.right.second + right_s2.left.second;
		if (temp > left_s1.max.second &&  temp > right_s2.max.second ) {
			result.max = make_pair(left_s1.right.first,temp);
		}
		else {
			if (left_s1.max.second > right_s2.max.second) {
				result.max = make_pair(left_s1.max.first, left_s1.max.second);
			}
			else {
				result.max = make_pair(right_s2.max.first, right_s2.max.second);
			}
		}
		if (left_s1.right.first == result.right.first) {
			result.right.second = temp;
		} 
		if (right_s2.left.first == result.left.first) {
			result.left.second = temp;
		}
	}
	else {
		if (left_s1.max.second > right_s2.max.second) {
			result.max = make_pair(left_s1.max.first, left_s1.max.second);
		}
		else {
			result.max = make_pair(right_s2.max.first, right_s2.max.second);
		}
	}

	return result;
}

struct node {
	pair<int, int> range;
	int index;
	s_struct node_s_struct;
};

void build(int p,int i,int n,vector<int> arr,vector<node> all_nodes) {
	if (i > n) {
		return;
	}
	else if (i == n) {
		all_nodes[p].range = pair<int, int>(i, n);
		all_nodes[p].index = p;
		//all_nodes[p].left = NULL;
		//all_nodes[p].right = NULL;
		all_nodes[p].node_s_struct.right = make_pair(arr[i-1],1);
		all_nodes[p].node_s_struct.left = make_pair(arr[i-1], 1);
		all_nodes[p].node_s_struct.max = make_pair(arr[i-1], 1);
	}
	else {
		all_nodes[p].range = pair<int, int>(i, n);
		all_nodes[p].index = p;
		int left = 2 * p;
		int right = 2 * p + 1;
		build(2*p, i, (i + n) / 2, arr,all_nodes);
		build(2*p + 1, (i + n) / 2 + 1, n, arr,all_nodes);
		all_nodes[p].node_s_struct = merge(all_nodes[left].node_s_struct, all_nodes[right].node_s_struct);
	}
}
s_struct find_range(node root, int start, int end,vector<node> all_nodes) {
	if (root == invalid()) {
		return invalid();
	}
	if (end < root.range.first || start > root.range.second) {
		return invalid();
	}
	if (start <= root.range.first && end >= root.range.second) {
		return (root.node_s_struct);
	}
	int left = 2*root.index;
	int right = 2 * root.index + 1;
	s_struct ptr_right = find_range(all_nodes[right], start, end,all_nodes);
	s_struct ptr_left = find_range(all_nodes[left], start, end,all_nodes);
	if (ptr_right == invalid() && ptr_left == invalid()) {
		return  invalid();
	}
	else if (ptr_right == invalid()) {
		return ptr_left;
	}
	else if (ptr_left == invalid()) {
		return ptr_right;
	}
	else {
		s_struct result = merge(ptr_left,ptr_right);
		return result;
	}
}

int main() {
	//pair<int,int>
	while (1) {
		int n, m;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		scanf("%d",&m);
		vector<node> all_nodes(m);
		vector<int> arr;
		FOR(i, 0, n) {
			int temp;
			scanf("%d", &temp);
			arr.push_back(temp);
		}
		build(0, 1, n, arr,all_nodes);
		FOR(i, 0, m) {
			int start, end;
			scanf("%d %d", &start, &end);
			s_struct res = find_range(all_nodes[0], start, end,all_nodes);
			printf("%d\n", res.max.second);
		}
	}
	return 0;
}