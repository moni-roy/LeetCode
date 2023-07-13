class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int neg = 0;
        int pos = 0;
        for (auto num : nums) {
            if(num == 0) {
                neg = 0;
                pos = 0;
            } else if(num > 0) {
                pos++;
                neg = neg > 0 ? neg + 1 : 0;
            } else {
                int tmp = pos;
                pos = neg > 0 ? neg + 1 : 0;
                neg = tmp + 1;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};