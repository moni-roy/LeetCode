class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        unordered_map<char, int> last;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (last.count(s[i])) {
                last.clear();
                ans++;
            }
            last[s[i]] = i;
        }
        if (last.size()) ans++;
        return ans;
    }
};