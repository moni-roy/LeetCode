class Solution {
public:
   int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int> > memo(nums.size(), vector<int>(nums.size(), 0));
        
        for (int left = nums.size() - 2; left > 0; --left) {
            for (int right = left; right < nums.size() - 1; ++right) {
                int max_coins = 0;
                for (int i = left; i <= right; ++i) {
                    int coins = nums[left-1] * nums[i] * nums[right+1];
                    coins += memo[left][i-1] + memo[i+1][right];
                    max_coins = max(max_coins, coins);
                }
                memo[left][right] = max_coins;
            }
        }
        return memo[1][nums.size() - 2];
    }
    
    // top-down
    int dp(vector<int> &nums, int left, int right, vector<vector<int>> &memo) {
        if(right < left) return 0;
        if(memo[left][right]!=-1) return memo[left][right];
        
        int res = 0;
        for(int i = left; i <= right; i++) {
            int value = nums[left-1] * nums[i] * nums[right+1];
            int remain = dp(nums, left, i - 1, memo) + dp(nums, i + 1, right, memo);
            res= max(value + remain, res);
        }
        memo[left][right] = res;
        return res;
    }
};