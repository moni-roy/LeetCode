class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for (int i = 0; i < (1<<n); ++i) {
            // bit count 
            int cnt = __builtin_popcount(i);
            if (cnt <= ans) continue;
            int mx = check(statements, i);
            ans = max(ans, mx ? cnt : 0);
        }
        return ans;
    }
private:
    int check(vector<vector<int>>& statements, int mask) {

        int n = statements.size();
        vector<int> cnt(n, -1);
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i)) {
                if(cnt[i] == 0) return 0;
                cnt[i] = 1;

                for (int j = 0; j < n; ++j) {
                    if (statements[i][j] == 1) {
                        if(cnt[j] == 0) return 0;
                        cnt[j] = 1;
                    }
                    else if (statements[i][j] == 0) {
                        if(cnt[j] == 1) return 0;
                        cnt[j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i)) {
                if(cnt[i] != 1) return 0;
            }
            else {
                if(cnt[i] == 1) return 0;
            }
        }
        return 1;
    }
};