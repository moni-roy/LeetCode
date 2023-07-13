class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]) - 1;
            if (nums[x] > 0) {
                nums[x] = -nums[x];
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};