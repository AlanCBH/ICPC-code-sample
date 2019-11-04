#include <iostream>
#include <string>
#include <queue>
using namespace std;

class car {
	public:
		int arrive_t;
		string side;
		int finish_t;
		car(int t,string s) {
			arrive_t = t;
			side = s;
		}
};

void push_car_in(queue<car*> *q,int size,int cur_time,int dur_time ) {
	int n = 0;
	while (n < size && !q->empty() && (q->front())->arrive_t<= cur_time ) {
		car* cptr = q->front();
		cptr->finish_t = cur_time+dur_time;
		n++;
		q->pop();
	}
}

int main ()
{
 int num = 0;
 cin >> num;
 for (int i = 0; i < num; i++) {
	int n,t,m;
	cin >> n >> t >> m;
	car* arr[m];
	queue<car*> left;
	queue<car*> right;
	for (int j = 0; j < m; j++) {
		int current;
		string s;
		cin >> current >> s;
		car* cptr = new car(current,s);
		arr[j] = cptr;
		if (s == "left") {
			left.push(cptr);		
		} else {
			right.push(cptr);
		} 
	}
	/////////////////////
	bool side_index = true;
	int earliest = 0;
	while ( !left.empty() && !right.empty() ) {
		car* lptr = left.front();
		car* rptr = right.front();
		if (side_index && (lptr->arrive_t <= earliest || lptr->arrive_t <= rptr->arrive_t) ) {
			
			if (lptr->arrive_t >= earliest) {
				earliest = lptr->arrive_t;
			}
			
			push_car_in(&left,n,earliest,t);
			side_index = false;
			earliest = earliest + t;
		
		} else if (side_index && lptr->arrive_t > rptr->arrive_t) {
			if (rptr->arrive_t > earliest) {
				earliest = rptr->arrive_t + t;
			} else {
				earliest = earliest + t;
			}
			side_index = false;

		} else if (!side_index && (rptr->arrive_t<=earliest||lptr->arrive_t>=rptr->arrive_t)) {
			
			if (rptr->arrive_t >= earliest) {
				earliest = rptr->arrive_t;
			}
			
			push_car_in(&right,n,earliest,t);
			side_index = true;
			earliest = earliest + t;
		
		} else if (!side_index && lptr->arrive_t < rptr->arrive_t) {
			if (lptr->arrive_t > earliest) {
				earliest = lptr->arrive_t + t;
			} else {
				earliest = earliest + t;
			}
			side_index = true;
		} 
	}
	
	if (left.empty()) {
		while ( !right.empty() ) {
			car* rptr = right.front();
			if (side_index) {
				if (rptr->arrive_t > earliest) {
					earliest = rptr->arrive_t+t;
				} else {
					earliest = earliest+t;
				}
				side_index = false;
			} else {
				if (rptr->arrive_t >= earliest) {
					earliest = rptr->arrive_t;
				}
				push_car_in(&right,n,earliest,t);
				side_index = true;
				earliest = earliest + t;
			}
		}
	} else {
		while ( !left.empty() ) {
			car* lptr = left.front();
			if (!side_index) {
			if (lptr->arrive_t > earliest) {
				earliest = lptr->arrive_t+t;
			} else {
				earliest = earliest+t;
			}
				side_index = true;
			} else {
				if (lptr->arrive_t >= earliest) {
					earliest = lptr->arrive_t;
				}
				push_car_in(&left,n,earliest,t);
				side_index = false;
				earliest = earliest + t;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		car* cptr = arr[j];
		cout << cptr->finish_t << endl;
		delete(cptr);
	}

 }

  return 0;
}
 