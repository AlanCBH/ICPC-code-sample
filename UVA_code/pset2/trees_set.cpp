#include <bits/stdc++.h>
using namespace std;

void merge_sets(set<char> &all_char,set<set<char>> &all_trees,char e1, char e2) {
	set<char> t1;
	for (set<set<char>>::iterator it = all_trees.begin(); it != all_trees.end(); it++) {
		if (it->find(e1) != it->end()) {
			t1 = *it;
			all_trees.erase(it);
			break;
		}
	}
	if (all_char.find(e2) != all_char.end()) {
		for (set<set<char>>::iterator it = all_trees.begin(); it != all_trees.end(); it++) {
			if (it->find(e2) != it->end()) {
				set<char> temp = *it;
				all_trees.erase(it);
				set<char> fin;
				merge(temp.begin(),temp.end(),t1.begin(),t1.end(),inserter(fin,fin.begin()));
				all_trees.insert(fin);
				break;
			}
		}
	}
	else {
		all_char.insert(e2);
		t1.insert(e2);
		all_trees.insert(t1);
	}
}


int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		set<set<char>> all_trees;
		//map<char, set<char>> char_map;
		set<char> all_char;
		while (1) {
			string s;
			cin >> s;
			if (s[0] == '(') {
				char e1 = s[1];
				char e2 = s[3];

				if (all_char.find(e1) != all_char.end()) {
					merge_sets(all_char,all_trees,e1,e2);
				}
				else if (all_char.find(e2) != all_char.end()) {
					merge_sets(all_char,all_trees, e2, e1);
				}
				else {
					set<char> new_set;
					new_set.insert(e1);
					new_set.insert(e2);
					all_char.insert(e1);
					all_char.insert(e2);
					all_trees.insert(new_set);
				}
			}
			else if (s[0] == '*') {
				continue;
			}
			else {
				int acorn = 0;
				for (int i = 0; i < s.size(); i+=2) {
					if (all_char.find(s[i]) == all_char.end()) {
						acorn++;
					}
				}
				printf("There are %d tree(s) ",all_trees.size());
				printf("and %d acorn(s).\n",acorn);
				break;
			}
		}

	}
	return 0;
}