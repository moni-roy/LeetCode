class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums) {
            sum += num;
        }
        for(int i = 0; i <=nums.size(); i++) sum-=i;
        return -1*sum;
    }
};