class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '+') ++i;
        else if (s[i] == '-') {
            sign = -1;
            ++i;
        }
        long long res = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + s[i] - '0';
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
            ++i;
        }
        return res * sign;
    }
};