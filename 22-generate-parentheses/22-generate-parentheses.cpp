class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(res, s, n, 0, 0);
        return res;
    }
    void dfs(vector<string>& res, string s, int n, int left, int right) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (left < n) dfs(res, s + '(', n, left + 1, right);
        if (right < left) dfs(res, s + ')', n, left, right + 1);
    }
};