class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[idx]) {
                nums[++idx] = nums[i];
                cnt = 1;
            } else {
                if (cnt < 2) {
                    nums[++idx] = nums[i];
                    cnt++;
                }
            }
        }
        return idx + 1;
    }
};