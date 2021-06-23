
class Solution {
public:
    static bool myfunc(tuple<int,int> t1, tuple<int,int> t2) {
		if (get<0>(t1) < get<0>(t2) ) {
			return true;
		} else {
			return false;
		}
	}
    int maxArea(vector<int>& height) {
        vector<tuple<int,int>> all_height;
        //map<int,int> all_index;
        map<int,int> used;
        int left_most = 0;
        int right_most = height.size()-1;
        for (int i = 0; i < height.size(); i++) {
            all_height.push_back(tuple<int,int>(height[i],i));
        }
        sort(all_height.begin(), all_height.end(), Solution::myfunc);
        int cur_max = 0;
        for (int i = 0; i < all_height.size(); i++) {
            tuple<int,int> h = all_height[i];
            int ind = get<1>(h);
            int tmp = get<0>(h)*(max(ind-left_most,right_most-ind));
            if (tmp > cur_max) {
                cur_max = tmp;
            }
            //update right_most, left_most;
            used[ind] = 1;
            
            while(used[left_most] != 0) {
                left_most++;
            }
            while(used[right_most] != 0) {
                right_most--;
            }
        }
        return cur_max;
        
        
    }
};