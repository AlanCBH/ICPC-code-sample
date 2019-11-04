#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	string read;
	cin >> num;
	getline(cin, read);
	for (int i = 0; i < num; i++) {
		map<int, set<int>> heard;
		getline(cin, read);
		while (read != '\n') {
			size sz;
			int p = stoi(read, &sz);
			int t = stoi(read.substr(sz));
			heard[p].insert(t);
			getline(cin, read);
		}
		map<set<int>, int> total_map;

	}

	return 0;
}