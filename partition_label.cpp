class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> sort_vec(s.length(),0);
        vector<int> res; 
        int cur_front = 0;
        map<int,int> number_hash;
        map<char,tuple<int,int>> intervals;
        for (int i = 0; i < s.length(); i++) {
            if ( get<0>(intervals[s[i]]) == 0 ) {
                get<0>(intervals[s[i]]) = i+1;
            }
             get<1>(intervals[s[i]]) = i+1;
        }
        map<char,tuple<int,int>>::iterator it;
        for (it = intervals.begin(); it != intervals.end(); it++) {
            number_hash[get<0>(it->second)-1] = get<1>(it->second)-1;
            sort_vec[(get<0>(it->second))-1]=1;
            //cout << (get<0>(it->second))-1 << (get<1>(it->second))-1 << "\n";
        }
        int cur_end = number_hash[0];
        for (int i = 0; i < sort_vec.size(); i++) {
            if (sort_vec[i] == 1) {
                //cout << i << "\n";
                if (cur_end >= i) {
                    cur_end = max(number_hash[i],cur_end);
                } else {
                    res.push_back(cur_end-cur_front+1);
                    cur_front = i;
                    cur_end = number_hash[i];
                } 
            }
        }
        res.push_back(cur_end-cur_front+1);
        return res;
        
    }
};