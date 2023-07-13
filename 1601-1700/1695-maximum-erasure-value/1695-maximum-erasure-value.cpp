class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> mp;
        int ans = 0, sm = 0;
        for(int i=0, j = 0; j<nums.size(); j++) {
            while(mp.find(nums[j])!=mp.end()) {
                mp.erase(nums[i]);
                sm -= nums[i];
                i++;
            }
            sm += nums[j];
            ans = ans<sm?sm:ans;
            mp.insert(nums[j]);
        }
        return ans;
    }
};