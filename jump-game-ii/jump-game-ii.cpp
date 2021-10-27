class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int min_step = 0, max_reach = 0, cur_reach = 0;
        for (int i = 0; i < n; i++) {
            if (i > max_reach) {
                min_step++;
                max_reach = cur_reach;
            }
            cur_reach = max(cur_reach, i + nums[i]);
        }
        return min_step;
    }
};