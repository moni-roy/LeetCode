class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, sum = 0;
        for (auto num :  nums) {
            if (max(0, num - sum) != 0) ans ++;
            sum += max(0, num - sum);
            if (sum >= nums[nums.size() - 1]) {
                break;
            }
        }
        return ans;
    }
};