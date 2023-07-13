class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int oddCount = 1, evenCount = 0;
        for(auto num: nums) {
            if(num&1) {
                res[oddCount] = num;
                oddCount += 2;
            }
            else {
                res[evenCount] = num;
                evenCount += 2;
            }
        }
        return res;
    }
};