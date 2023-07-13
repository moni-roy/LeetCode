class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t, freq_s;
        for (auto c : t) freq_t[c]++;
        
        // sliding window
        int l = 0, r = 0;
        int min_l = 0, min_r = 0;
        int min_len = INT_MAX;
        int cnt = 0;
        while (r < s.size()) {
            if (freq_t[s[r]] > 0) {
                freq_s[s[r]]++;
                if (freq_s[s[r]] <= freq_t[s[r]]) cnt++;
            }
            r++;
            
            while (cnt == t.size()) {
                if (r - l < min_len) {
                    min_len = r - l;
                    min_l = l;
                    min_r = r;
                }
                if (freq_t[s[l]] > 0) {
                    freq_s[s[l]]--;
                    if (freq_s[s[l]] < freq_t[s[l]]) cnt--;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_l, min_len);
    }
};