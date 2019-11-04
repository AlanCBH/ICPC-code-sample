#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;



int main() {
	int num;
	scanf("%d",&num);
	map<char,vector<char>> node_map;
	map<char, bool> node_visit;
	char c = 'A';
	for (int i = 0; i < num; i++) {
		node_visit[c] = false;
		c = c + 1;
	}
	int connection;
	scanf("%d\n",&connection);
	queue<char> temp;
	char w1, w2, w3;
	scanf("%c%c%c\n",&w1,&w2,&w3);
	temp.push(w1);
	temp.push(w2);
	temp.push(w3);
	node_visit[w1] = true;
	node_visit[w2] = true;
	node_visit[w3] = true;
	for (int i = 0; i < connection; i++) {
		char a, b;
		scanf("%c%c\n",&a,&b);
		node_map[a].push_back(b);
		node_map[b].push_back(a);
		printf("%c%c\n",a,b);
		fflush(stdout);
	}
	queue<char> wake;
	int result = 0;
	while ( !temp.empty() ) {
		int size = temp.size();
		
		while ( !wake.empty() ) {
			node_visit[wake.front()] = true;
			wake.pop();
		}
		for (int n = 0; n < size; n++) {
			char cur = temp.front();
			for (int i = 0; i < node_map[cur].size(); i++) {
				char next = node_map[cur][i];
				printf("%c\n", &next);
				int count = 0;
				for (int j = 0; j < node_map[next].size(); j++) {
					if (node_visit[node_map[next][j]]) {
						count++;
						if (count >= 3) {
							temp.push(next);
							wake.push(next);
							break;
						}
					}
				}
			}
			temp.pop();
		}
		
	}


	bool all = true;
	c = 'A';
	for (int i = 0; i < num; i++) {
		if (!node_visit[c]) {
			all = false;
			break;
		}
		c = c + 1;
	}
	if (all) {
		printf("WAKE UP IN, %d, YEARS",result);
	}
	else {
		printf("THIS BRAIN NEVER WAKES UP");
	}
	return 0;
}