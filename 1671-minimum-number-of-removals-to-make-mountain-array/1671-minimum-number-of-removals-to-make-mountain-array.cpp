class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        return usingLIS(nums);
    }
private:
    int usingLIS(vector<int> &nums) {
        vector <int> rev(nums.begin(), nums.end());
        reverse(rev.begin(), rev.end());
        vector <int> lisLeft, lisRight;
        lisLeft = LIS(nums);
        lisRight = LIS(rev);
        reverse(lisRight.begin(), lisRight.end());
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if(lisLeft[i] >= 2 && lisRight[i] >= 2)
                ans = max(ans, lisLeft[i] + lisRight[i] - 1);
        }
        return ans != INT_MIN ? nums.size() - ans : nums.size();
    }
    vector<int> LIS(vector<int> &arr) {
        vector<int> lis, dp(arr.size(), 1);
        for(int i = 0; i < arr.size(); i++) {
            if(lis.empty() || arr[i] > lis.back()) {
                lis.push_back(arr[i]);
                dp[i] = lis.size();
            } else {
                int j = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
                lis[j] = arr[i];
                dp[i] = j + 1;
            }
        }
        
        return dp;
    }
};