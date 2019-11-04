#include <iostream>
#include <vector>
using namespace std;
class node {
	public:
		vector<node*> *adjacents = NULL;
		long long values = 0;
		long long next_values = 0;
		node(long long val) { 
			adjacents = new vector<node*>;
			values = val; 
			next_values = val;
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

long long cal_total(vector<node*> infected) {
	long long result = 0;
	for (long long i = 0; i < infected.size(); i++) {
			node* itp = infected.at(i);
			if (itp->values != 0 && itp->next_values == 0) {
				result += itp->values;
				itp->values = 0;
			}
	}
	return result;
}
void set_next(vector<node*> infected) {
	for (long long i = 0; i < infected.size(); i++) {
			node* itp = infected.at(i);
			if (itp->next_values != 0  && itp->values == 0) {
				itp->values = itp->next_values;
				itp->next_values = 0;
			}
	}
}


int main ()
{
	long long n,m,s,t;
	cin >> n >> m >> s >> t;
	graph my_graph = graph();
	for (long long i = 0; i < n; i++) {
		node* nptr = new node(0);
		my_graph.add_node(nptr);
	}
	for (long long i = 0; i < m; i ++) {
		long long e1,e2;
		cin >> e1 >> e2;
		node* ptr1 = my_graph.all_nodes.at(e1);
		node* ptr2 = my_graph.all_nodes.at(e2);
		my_graph.add_edge(ptr1,ptr2);
	}
	
	node* ns = my_graph.all_nodes.at(s);
	my_graph.start = ns;
	ns->values = 1;
	vector<node*> *pin = new vector<node*>;
	vector<node*> infected = *pin;
	infected.push_back(ns);


	for (long long i = 0; i < t; i++) {
		//cout << cal_total(infected) << endl;
		long size = infected.size();
		//cout << size << endl; 
		for (long long j = 0; j < size; j++) {
			node* it = infected.at(j);
			//cout << it->values << endl; 
			vector<node*> *ptr = (it)->adjacents;
			for (long long k = 0; k < ptr->size(); k++) {
				node* adj = ptr->at(k);
				if ((it)->values != 0) {
					adj->next_values += (it)->values;
					infected.push_back(adj);
				}
			}
			(it)->values = 0;
		}
		infected.erase (infected.begin(),infected.begin()+size);
		set_next(infected);
	}
	long long result = cal_total(infected);
	
	
	cout << result << endl;
	return 0;
}