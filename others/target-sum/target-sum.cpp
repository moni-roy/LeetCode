class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0 , nums, target);
    }
    
    int dfs(int p, vector<int>& nums, int target) {
        if(p==nums.size()) {
            return (target == 0);
        }
        int res = dfs(p+1, nums, target - nums[p]);
        res += dfs(p+1, nums, target + nums[p]);
        return res;
    }
};