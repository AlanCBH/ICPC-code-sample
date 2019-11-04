#include <iostream>
#include <vector>
#include <stdio>
using namespace std;
class point {
	public:
		int x,y;
		point(int x_cor, int y_cor) {
			x = x_cor;
			y = y_cor;
		}
};
class edge {
	public:
		point x;
		point y;
	edge(point xp, point yp) {
		x = xp;
		y = yp;
	}
};

bool intersection(edge e1, edge e2) {
	point x1 = e1.x;
	point y1 = e1.y;
	
	point x2 = e2.x;
	point y2 = e2.y;

	if ((min(x1.x,y1.x) < max(x2.x,y2.x)) &&
		(min(x2.x,y2.x) < max(x1.x,y1.x)) &&
		(min(x1.y,y1.y) < max(x2.y,y2.y)) &&
		(min(x2.y,y2.y) < max(x1.y,y1.y)) ) {
		return true;
	} else {
		return false;
	}


}


class node {
	public:
		vector<node*> *adjacents = NULL;

		long long values = 0;
		long long used_values = 0;
		node(long long val) { 
			adjacents = new vector<node*>;
			values = val; 
			used_values = val;
		} 
	
};
class graph {
	public:
		node* start;
		vector<node*>* all_node = new vector<node*>;
		vector<node*> all_nodes = *all_node;
		graph() {
			start = NULL;
		}
	void add_node(node* ptr) {
		this->all_nodes.push_back(ptr);
	}
	void add_edge(node* ptr1, node* ptr2) {
		(ptr1->adjacents)->push_back(ptr2);
		(ptr2->adjacents)->push_back(ptr1);
	}
};



int main ()
{
	return 0;
}