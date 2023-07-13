class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto a: arr) {
            ans = max(ans, m[a - difference] + 1);
            m[a] = max(m[a], m[a - difference] + 1);
        }
        return ans;
    }
};