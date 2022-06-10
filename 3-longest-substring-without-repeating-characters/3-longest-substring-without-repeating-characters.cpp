class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0, prevIdx = -1;
        for (int i = 0; i < s.size(); i++){
            if (m.find(s[i]) != m.end()){
                prevIdx = max(prevIdx, m[s[i]]);
            }
            ans = max(ans, i - prevIdx);
            m[s[i]] = i;
        }
        return ans;
    }
};