class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freg(26, 0);
        for (char c : s) {
            freg[c - 'a'] ++;
        }
        for (char c : t) {
            if (freg[c-'a'] == 0) {
                return c;
            }
            freg[c-'a'] --;
        }
        return ' ';
    }
};