class Solution {
public:
    vector<vector<int>> sv;
    int numDistinct(string s, string t) {
        sv = vector<vector<int>>(s.size()+1, vector(t.size()+1, -1));
        return dp(0, 0, s, t);
    }
    int dp(int i, int j, string &s, string &t) {
        if(j == t.size()) {
            return 1;
        }
        if(i >= s.size()) return 0;
        if(sv[i][j] != -1) return sv[i][j];
        int ret = dp(i+1, j, s, t);
        if(s[i] == t[j]) {
            ret += dp(i+1, j+1, s, t);
        }
        sv[i][j] = ret;
        return ret;
    }
};