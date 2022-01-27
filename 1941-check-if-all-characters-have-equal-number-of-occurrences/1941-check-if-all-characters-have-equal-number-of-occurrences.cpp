class Solution {
public:
    bool areOccurrencesEqual(string s) {
        return usingHashMap(s);
    }
private:
    bool usingHashMap(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        int count = m[s[0]];
        for (int i = 1; i < s.size(); i++) {
            if (m[s[i]] != count) {
                return false;
            }
        }
        return true;
    }
};