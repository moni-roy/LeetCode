class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int> > memo(nums.size(), vector<int>(nums.size(), -1));
        return dp(nums, 1, nums.size()-2, memo);
    }
    
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