class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<string> curList;
        dfs(0, s, curList, ans, dp);
        return ans;
    }
    
    void dfs(int start, string &s, vector<string> &curList, vector<vector<string> > &ans, vector<vector<bool>> &dp) {
        if(start >= s.size()) {
            ans.push_back(curList);
            return;
        }
        for(int end = start; end < s.size(); end++) {
            if(s[start] == s[end] && (end - start <=2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                curList.push_back(s.substr(start, end-start + 1));
                dfs(end+1, s, curList, ans, dp);
                curList.pop_back();
            }
        }
    }
};