class Solution {
public:
    int myAtoi(string s) {
        long temp = 0;
        bool first_nonspace = false;
        bool negative = false;
        for (int i = 0; i < s.length(); i++) {
            if (!first_nonspace && s[i] == ' ') {
                continue;
            }
            else if (s[i] == '-' && !first_nonspace) {
                negative = true;
                first_nonspace = true;
            }
            else if (s[i] == '+' && !first_nonspace) {
                first_nonspace = true;
            }
            else if (isdigit(s[i])) {
                temp = temp*10 + (s[i]-'0');
                if (temp > (long)INT_MAX+1 && negative) {
                    temp = (long)INT_MAX+1;
                } else if (temp > INT_MAX && !negative) {
                    temp = INT_MAX;
                }
                first_nonspace = true;
            } else {
                break;
            }
        }
        if (negative) {
            temp = -temp;
        }
        return int(temp);
    }
};