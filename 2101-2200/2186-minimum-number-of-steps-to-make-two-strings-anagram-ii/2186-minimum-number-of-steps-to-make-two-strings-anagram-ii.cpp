class Solution {
public:
    int minSteps(string s, string t) {
        // min steps to make anagram of s to t
        
        // edge case
        if (s.size() == 0) return t.size();
        if (t.size() == 0) return s.size();

        // init
        int s_count[26] = {0};
        int t_count[26] = {0};
        int res = 0;

        // count
        for (int i = 0; i < s.size(); i++) {
            s_count[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            t_count[t[i] - 'a']++;
        }

        // compare
        for (int i = 0; i < 26; i++) {
            res += abs(s_count[i] - t_count[i]);
        }

        return res;
    }
};