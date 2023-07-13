class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<string> path;
        dfs(0, s, dict, path, ans);
        return ans;
    }
    void dfs(int i, string& s, unordered_set<string>& dict, vector<string>& path, vector<string>& ans) {
        if(i == s.size()) {
            string tmp;
            for(auto& p: path) {
                tmp += p + " ";
            }
            ans.push_back(tmp.substr(0, tmp.size() - 1));
            return;
        }
        for(int j = i; j < s.size(); ++j) {
            string word = s.substr(i, j - i + 1);
            if(dict.count(word)) {
                path.push_back(word);
                dfs(j + 1, s, dict, path, ans);
                path.pop_back();
            }
        }
    }
};