class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (abs(s[i] - s[i + 1]) == 32) {
                s.erase(i, 2);
                i = max(-1, i - 2);
                n -= 2;
            }
        }
        return s;
    }
};