class Solution {
public:
    int maxLength(vector<string>& s) {
        return dfs(s, 0, "");
    }
    
    int dfs(vector<string> &s, int p, string t) {
        unordered_set<char> st(t.begin(), t.end());
        if (st.size() != t.size()) return 0;
        int ret = t.size();
        for(int i = p; i < s.size(); i++) {
            ret = max(ret, dfs(s, i + 1, t + s[i]));
        }
        return ret;
    }
};