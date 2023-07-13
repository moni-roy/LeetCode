class Solution {
public:
    bool check(vector<int>& nums) {
        int down = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) down ++;
        }
        if(down > 1) return false;
        if(down == 1) return nums[0] >= nums[nums.size() - 1];
        return down <= 1;
    }
};