class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string tmp;
        dfs(digits, dict, 0, tmp, res);
        return res;
    }
    void dfs(string digits, string dict[], int index, string tmp, vector<string> &res) {
        if (index == digits.size()) {
            res.push_back(tmp);
            return;
        }
        string s = dict[digits[index] - '0'];
        for (int i = 0; i < s.size(); ++i) {
            tmp.push_back(s[i]);
            dfs(digits, dict, index + 1, tmp, res);
            tmp.pop_back();
        }
    }
};