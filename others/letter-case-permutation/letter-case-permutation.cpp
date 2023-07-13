class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ret;
        dfs(s, ret);
        return ret;
    }
    void dfs(string s, vector<string> &ret, int i = 0) {
        if(i == s.size()) {
            ret.push_back(s);
            return;
        }
        dfs(s, ret, i+1);
        if(isalpha(s[i])) {
            char c = s[i];
            if(s[i] >= 'A' && s[i] <='Z') s[i] = s[i]-'A' + 'a';
            else s[i] = s[i] - 'a' + 'A';
            dfs(s, ret, i+1);
            s[i] = c;
        }
    }
};