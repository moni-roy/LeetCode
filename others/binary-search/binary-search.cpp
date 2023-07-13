class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        cout<<l<<endl;
        return (l >= nums.size() || nums[l] != target) ? -1 : l;
    }
};