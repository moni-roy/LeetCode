class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> mins(nums.size(), INT_MAX);
        mins[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mins[i] = min(mins[i - 1], nums[i]);
        }
        stack<int> stk;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > mins[i]) {
                while (!stk.empty() && stk.top() <= mins[i]) stk.pop();
                if (!stk.empty() && stk.top() < nums[i]) return true;
                stk.push(nums[i]);
            }
        }
        return false;
    }
};