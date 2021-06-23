class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int num_M = num/1000;
        for (int i = 0; i < num_M; i++) {
            roman += "M";
        }
        int num_C = 0;
        int res = num%1000;
        if (res%500 >= 400) {
            roman += "C";
            if (res >= 900) {
                roman += "M";
            } else {
                roman += "D";
            }
        } else if (res/500 == 1) {
            roman += "D";
            res = res%500;
            num_C = res/100;
            
        } else {
            num_C = res/100;
            
        }
        for (int i = 0; i < num_C; i++) {
            roman += "C";
        }
        int num_X = 0;
        res = res%100;
        if (res%50 >= 40) {
            roman += "X";
            if (res >= 90) {
                roman += "C";
            } else {
                roman += "L";
            }
        } else if (res/50 == 1) {
            roman += "L";
            res = res%50;
            num_X = res/10;
           
        } else {
            num_X = res/10;
        }
        for (int i = 0; i < num_X; i++) {
            roman += "X";
        }
        int num_I = 0;
        res = res%10;
        if (res%5 >= 4) {
            roman += "I";
            if (res >= 9) {
                roman += "X";
            } else {
                roman += "V";
            }
        } else if (res/5 == 1) {
            roman += "V";
            res = res%5;
            num_I = res;
           
        } else {
            num_I = res;
        }
        for (int i = 0; i < num_I; i++) {
            roman += "I";
        }
        return roman;
        
    
    }
};