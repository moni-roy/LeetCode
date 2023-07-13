class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        return usingHashMap(nums1, nums2, nums3, nums4);
    }
private:
    int usingHashMap(vector<int> &nums1, vector<int> &nums2, vector<int> nums3, vector<int> nums4) {
        unordered_map<int, int> sumTwo;

        for(auto a: nums1) 
            for(auto b: nums2) 
                sumTwo[a+b] ++;
        
        int ans = 0;
        for(auto a: nums3)
            for(auto b: nums4)
                ans += sumTwo[-1*(a+b)];

        return ans;
    }
};