class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vs(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vs[i] == 0) {
                dfs(i, vs, isConnected);
                ans ++;
            }
        }
        return ans;
    }
    void dfs(int p, vector<int> &vs, vector<vector<int>>& is) {
        if(vs[p]) return;
        vs[p] = 1;
        for(int i = 0; i < is.size(); i++) {
            if(!vs[i] && i!=p && is[p][i]) dfs(i, vs, is);
        }
    }
};