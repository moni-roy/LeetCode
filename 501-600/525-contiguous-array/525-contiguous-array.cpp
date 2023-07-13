class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        return greedy(nums);
    }
private:
    int greedy(vector<int>& nums) {
        int n = nums.size(), sum = 0, max_len = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (m.find(sum) != m.end()) {
                max_len = max(max_len, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return max_len;
    }
};