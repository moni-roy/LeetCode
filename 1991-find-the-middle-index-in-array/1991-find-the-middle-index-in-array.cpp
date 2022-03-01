class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        return withoutExtraSpace(nums);
        // return usingExtraSpace(nums);
    }
private:
    int withoutExtraSpace(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0, index = 0;
        while(index < nums.size()) {
            totalSum -= nums[index];
            if(totalSum == leftSum) {
                return index;
            }
            leftSum += nums[index];
            index++;
        }
        return -1;
    }
    int usingExtraSpace(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n+1, 0), rightSum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            leftSum[i+1] = leftSum[i] + nums[i];
        }
        for (int i = n-1; i >= 0; --i) {
            rightSum[i] = rightSum[i+1] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            if (leftSum[i] == rightSum[i+1]) {
                return i;
            }
        }
        return -1;
    }
};