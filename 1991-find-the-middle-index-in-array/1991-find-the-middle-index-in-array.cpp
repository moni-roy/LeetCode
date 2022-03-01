class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n+1, 0), rightSum(n+1, 0);
        for(int i = 1; i <= n; i++) leftSum[i] = leftSum[i-1] + nums[i-1];
        for(int i = n-1; i >= 0; i--) rightSum[i] = rightSum[i+1] + nums[i];
        for(int i = 0; i < n; i++) {
            if(leftSum[i] == rightSum[i+1]) return i;
        }
        return -1;
    }
};