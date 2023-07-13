class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, id = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (auto num : nums) {
            sum += num;
            if (mp.find(sum % k) == mp.end())
                mp[sum % k] = id + 1;
            else if (mp[sum % k] < id) return true;
            id ++;
        }
        return false;
    }
};