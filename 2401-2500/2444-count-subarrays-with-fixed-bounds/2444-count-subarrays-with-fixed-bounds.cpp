class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int cnt = 0, minPos = -1, maxPos = -1, left = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) left = i;
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;
            
            ans += max(0, min(minPos, maxPos) - left);
            
        }
        ans += (cnt * (cnt + 1) / 2);
        return ans;
    }
};