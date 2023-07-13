class Solution {
public:
    string greatestLetter(string s) {
        vector<int> count(128, 0);
        for (char c : s) {
            count[c]++;
        }
        for (auto c = 'Z'; c >= 'A'; c--) {
            if (count[c] && count[tolower(c)]) {
                return string(1, c);
            }
        }
        return "";
    }
};