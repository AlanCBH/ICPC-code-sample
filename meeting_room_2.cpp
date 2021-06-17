#include<bits/stdc++.h>
using namespace std;
class Interval {
	public: 
		int start,end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
	/*public: 
	bool myfunction(Interval i, Interval j) {
		return i.start < j.start;
	}*/
};

class Compare {
	bool operator() (Interval i, Interval j) {
		if (i.start < j.start) {
			return true;
		} else {
			return false;
		}
	}	
};
class Solution {
	public:
		static bool myfunction(const Interval &i, const Interval &j) {
			return i.start < j.start;
		}
		static int minMeetingRooms(vector<Interval> &intervals) {
			if (intervals.size() == 0) {
				return 0;
			}
			sort(intervals.begin(), intervals.end(), Solution::myfunction);
			priority_queue<int,vector<int>,greater<int> > pq;
			pq.push(intervals[0].end);
			for (int i = 1; i < intervals.size(); i++) {
				if (intervals[i].start >= pq.top()) {
					pq.pop();
				}
				pq.push(intervals[i].end);	
			}
			return pq.size();
		}

};
int main() {
	vector<Interval> intervals;
	intervals.push_back(Interval(0,5));
	intervals.push_back(Interval(15,20));
	intervals.push_back(Interval(7,9));
	intervals.push_back(Interval(2,3));
	intervals.push_back(Interval(2,10));
	cout << Solution::minMeetingRooms(intervals);
	return 0;
}
