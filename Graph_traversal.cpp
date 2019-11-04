#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct node {
		vector<node*> adjacents;
		bool visited = false;
};

class graph {
	public:
		node* start;
		vector<node*> all_nodes;
		graph() {
			start = NULL;
		}
	void add_node(node* ptr) {
		this->all_nodes.push_back(ptr);
	}
	void add_edge(node* ptr1, node* ptr2) {
		(ptr1->adjacents).push_back(ptr2);
		(ptr2->adjacents).push_back(ptr1);
	}
	void BFS(node* ptr) {
		queue<node*> toVisit;
		toVisit.push(ptr);
		while(!toVisit.empty()) {
			int size = toVisit.size();
			for(int i = 0; i < size; i++) {
				node* temp = toVisit.front();
				for (int j = 0; j < (temp->adjacents).size(); j++) {
					node* adj_temp = temp->adjacents[j];
					if (!adj_temp->visited) {
						toVisit.push(adj_temp);
					}
				}
				temp->visited = true;
				toVisit.pop();
			}	
		}
	}
};

int main ()
{
	int n,m;
	scanf("%d %d",&n,&m);
	graph* house = new graph(); 
	for (int i = 0; i < n; i++) {
		node* new_node = new node();
		house->add_node(new_node);
	}
	house->start = house->all_nodes[0];
	for (int i = 0; i < m; i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		house->add_edge(house->all_nodes[x-1],house->all_nodes[y-1]);
	}
	house->BFS(house->start);

	int size = house->all_nodes.size();
	bool connected = true;
	for (int i = 0; i < size; i++) {
		node* temp = house->all_nodes[i];
		if (!temp->visited) {
			connected = false;			
			printf("%d\n",i+1);
			fflush(stdout);
		}
	}
	if (connected) {
		printf("Connected\n");
		fflush(stdout);
	}
	return 0;
}