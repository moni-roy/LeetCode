class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ret;
        dfs(1, n, k, ret);
        return ret;
    }
    void dfs(int p, int n, int k, vector<vector<int>> &ret, vector<int> v = {}) {
        if(k == 0){
            ret.push_back(v);
            return;
        }
        for(int i = p; i<=n; i++) {
            v.push_back(i);
            dfs(i+1, n, k-1, ret, v);
            v.pop_back();
        }
    }
};