class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0;
        for(auto n: nums) {
            cur = n ? cur + 1 : 0;
            res = (cur > res) ? cur : res;
        }
        return res;
    }
};