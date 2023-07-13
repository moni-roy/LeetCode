class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int> > m;
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }
        vector<int> dp(n, 0);
        dp[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            auto &v = m[arr[cur]];
            v.push_back(cur-1);
            v.push_back(cur+1);
            for (auto &i : v) {
                if (i == n - 1) return dp[cur];
                if (i < 0 || i >= n) continue;
                if (dp[i] == 0) {
                    dp[i] = dp[cur] + 1;
                    q.push(i);
                }
            }
            v.clear();
        }
        return dp[n - 1];
    }
};