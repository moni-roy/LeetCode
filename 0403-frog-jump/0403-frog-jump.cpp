class Solution {
private:
     unordered_map<int, int> mark;
    int dp[2001][2001];
    int dfs(vector<int>& stones, int n, int idx, int pre) {
        if (idx == n - 1)  return 1;
        if (dp[idx][pre] != -1) return dp[idx][pre];
        int ret = false;
        for (int nidx = pre - 1; nidx <= pre + 1; nidx++) {
            if (nidx > 0 && mark.find(stones[idx] + nidx) != mark.end()) {
                ret = ret || dfs(stones, n, mark[stones[idx] + nidx], nidx);
            }
        }
        return dp[idx][pre] = ret;
    }
public:
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < stones.size(); i++) {
            mark.insert({stones[i], i});
        }
        return dfs(stones, stones.size(), 0, 0);
    }
};