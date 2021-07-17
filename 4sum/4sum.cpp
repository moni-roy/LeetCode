class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int> &nums, int target, int s, int k) {
        vector<vector<int>>res;
        if(s == nums.size() || nums[s]*k > target || target > nums.back()*k) return res;
        if(k == 2) return twoSum(nums, target, s);
        for(int i = s; i<nums.size(); i++) {
            if(i == s || nums[i-1] != nums[i]) {
                auto ret = kSum(nums, target-nums[i], i + 1, k - 1);
                for(auto v: ret) {
                    v.push_back(nums[i]);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int> &nums, int target, int s) {
        vector<vector<int> > res;
        set<int> st;
        int prev = INT_MIN;
        for(int i = s; i< nums.size(); i++) {
            if(res.empty() || nums[i] != prev) {
                if(st.find(target - nums[i]) != st.end()) {
                    res.push_back({target - nums[i], nums[i]});
                    prev = nums[i];
                }
            }
            st.insert(nums[i]);
        }
        return res;
    }
};