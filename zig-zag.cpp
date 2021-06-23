class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int tmp = numRows*2-2; //tmp is always even
        vector<string> vec_res;
        for (int i = 0; i < numRows; i++) {
            vec_res.push_back("");
        }
        for (int i = 0; i < s.length(); i++) {
            if (i%tmp <= tmp/2) {
                vec_res[(i%tmp)] += s[i];
            } else {
                vec_res[tmp-(i%tmp)] += s[i];
            }
        }
        string res = "";
        for (int i = 0; i < numRows; i++) {
            res.append(vec_res[i]);
            //cout << vec_res[i] << "\n";
        }
        return res;
    }
};