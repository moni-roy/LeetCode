class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int sm = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(sm + nums[i] < nums[i]) sm = nums[i];
            else sm += nums[i];
            mx = mx < sm ? sm : mx;
        }
        return mx;
    }
};