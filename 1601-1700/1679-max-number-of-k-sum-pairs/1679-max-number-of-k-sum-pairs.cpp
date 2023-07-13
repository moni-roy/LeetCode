class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> preCount;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            preCount[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == k - nums[i]) {
                int t = floor(preCount[nums[i]] / 2.0);
                res += t;
                preCount[nums[i]] -= t*2;
            }
            else {
                int t = min(preCount[nums[i]], preCount[k - nums[i]]);
                res += t;
                preCount[nums[i]] -= t;
                preCount[k - nums[i]] -= t;
            }
        }
        return res;
    }
};