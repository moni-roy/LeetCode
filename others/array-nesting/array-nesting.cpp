class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        vector<int> vs(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(vs[i] == 0){
                ret = max(ret, dfs(i, vs, nums));
            }
        }
        return ret;
    }
    int dfs(int p, vector<int> &vs, vector<int> &nums){
        vs[p] = 1;
        int ret = 1;
        if(vs[nums[p]] == 0) {
            ret += dfs(nums[p], vs, nums);
        }
        return ret;
    }
};