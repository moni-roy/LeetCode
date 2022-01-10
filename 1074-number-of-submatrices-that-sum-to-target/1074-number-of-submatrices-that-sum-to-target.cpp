class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0) sum[i][j] = matrix[i][j];
                else sum[i][j] = sum[i-1][j] + matrix[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = i; j < m; ++j) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cur = 0;
                for(int k = 0; k < n; ++k) {
                    cur += sum[j][k] - (i == 0 ? 0 : sum[i-1][k]);
                    ans += mp[cur - target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};