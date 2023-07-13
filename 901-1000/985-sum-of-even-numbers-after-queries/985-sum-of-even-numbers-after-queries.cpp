class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
            mp[i] = nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][1];
            int val = queries[i][0];
            if (mp[index] % 2 == 0) {
                sum -= mp[index];
            }
            mp[index] += val;
            if (mp[index] % 2 == 0) {
                sum += mp[index];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};