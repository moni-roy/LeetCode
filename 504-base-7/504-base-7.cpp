class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if (num == 0) return "0";
        bool isNeg = false;
        if (num < 0) {
            isNeg = true;
            num = -num;
        }
        while (num) {
            res.push_back(num % 7 + '0');
            num /= 7;
        }
        if (isNeg) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};