class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<nums.size() && diff!=0; i++) {
            int l = i+1, h = nums.size()-1;
            while(l<h) {
                int sm = nums[i] + nums[l] + nums[h];
                if(abs(target-sm) < abs(diff)) diff = target-sm;
                if(sm < target) l++;
                else h--;
            }
        }
        return target-diff;
    }
};