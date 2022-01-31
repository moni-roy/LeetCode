class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto account: accounts) {
            int total = accumulate(account.begin(), account.end(), 0);
            ans = ans < total ? total : ans;
        }
        return ans;
    }
};