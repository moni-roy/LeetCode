class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> new_nums(n/2);
        for(int i = 0; i < n/2; i++)
            if(i & 1)
                new_nums[i] = max(nums[2*i], nums[2*i+1]);
            else
                new_nums[i] = min(nums[2*i], nums[2*i+1]);
        return minMaxGame(new_nums);
    }
};